#include <iostream>
#include <windows.h>
#include <string>
#include "Board.h"

using namespace std;

// Global game state for GUI access
Board gameBoard;
bool isWhiteTurn = true;
int selectedX = -1;
int selectedY = -1;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    const int tileSize = 80;
    const int offsetX = 40;
    const int offsetY = 40;

    switch (uMsg)
    {
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        // Draw board
        for (int y = 0; y < 8; ++y)
        {
            for (int x = 0; x < 8; ++x)
            {
                RECT rect = { offsetX + x * tileSize, offsetY + y * tileSize, offsetX + (x + 1) * tileSize, offsetY + (y + 1) * tileSize };

                HBRUSH brush;
                if (selectedX == x && selectedY == y) {
                    brush = CreateSolidBrush(RGB(150, 200, 150)); // Selected square (greenish)
                }
                else if ((x + y) % 2 == 0) {
                    brush = CreateSolidBrush(RGB(240, 217, 181)); // Light square
                }
                else {
                    brush = CreateSolidBrush(RGB(181, 136, 99)); // Dark square
                }

                FillRect(hdc, &rect, brush);
                DeleteObject(brush);

                Piece* p = gameBoard.getPiece(x, y);
                if (p != nullptr)
                {
                    char sym = p->getSymbol();
                    bool isWhite = p->getIsWhite();
                    string s(1, sym);

                    SetBkMode(hdc, TRANSPARENT);
                    if (isWhite) {
                        SetTextColor(hdc, RGB(255, 255, 255)); // White piece
                    }
                    else {
                        SetTextColor(hdc, RGB(0, 0, 0)); // Black piece
                    }

                    HFONT hFont = CreateFontA(40, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
                        CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, "Arial");
                    HFONT hOldFont = (HFONT)SelectObject(hdc, hFont);

                    DrawTextA(hdc, s.c_str(), -1, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

                    SelectObject(hdc, hOldFont);
                    DeleteObject(hFont);
                }
            }
        }

        // Draw turn text
        RECT textRect = { offsetX, offsetY + 8 * tileSize + 10, offsetX + 8 * tileSize, offsetY + 8 * tileSize + 50 };
        SetBkMode(hdc, TRANSPARENT);
        SetTextColor(hdc, RGB(255, 255, 255));
        string turnText = isWhiteTurn ? "Turn: White" : "Turn: Black";
        DrawTextA(hdc, turnText.c_str(), -1, &textRect, DT_LEFT | DT_SINGLELINE);

        EndPaint(hwnd, &ps);
    }
    return 0;

    case WM_LBUTTONDOWN:
    {
        int mouseX = LOWORD(lParam);
        int mouseY = HIWORD(lParam);

        int x = (mouseX - offsetX) / tileSize;
        int y = (mouseY - offsetY) / tileSize;

        if (x >= 0 && x < 8 && y >= 0 && y < 8)
        {
            if (selectedX == -1) // First click (select piece)
            {
                Piece* p = gameBoard.getPiece(x, y);
                if (p != nullptr && p->getIsWhite() == isWhiteTurn)
                {
                    selectedX = x;
                    selectedY = y;
                    InvalidateRect(hwnd, NULL, TRUE);
                }
            }
            else // Second click (move piece)
            {
                if (x == selectedX && y == selectedY) {
                    // Deselect if clicked on the same piece
                    selectedX = -1;
                    selectedY = -1;
                    InvalidateRect(hwnd, NULL, TRUE);
                }
                else {
                    // Attempt to move
                    bool success = gameBoard.movePiece(selectedX, selectedY, x, y, isWhiteTurn);
                    if (success)
                    {
                        isWhiteTurn = !isWhiteTurn;
                    }
                    selectedX = -1;
                    selectedY = -1;
                    InvalidateRect(hwnd, NULL, TRUE);
                }
            }
        }
    }
    return 0;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProcA(hwnd, uMsg, wParam, lParam);
}

int main()
{
    cout << "--- Chess Game GUI Initialized ---" << endl;
    cout << "Check the separate 'Chess Game GUI' window for the game board." << endl;
    cout << "Note: Pawn promotion will still ask for input here in the console!" << endl;

    HINSTANCE hInstance = GetModuleHandle(NULL);
    const char CLASS_NAME[] = "ChessWindowClass";

    WNDCLASSA wc = { };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = CreateSolidBrush(RGB(40, 40, 40)); // Dark background

    RegisterClassA(&wc);

    HWND hwnd = CreateWindowExA(
        0,
        CLASS_NAME,
        "Chess Game GUI",
        WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME ^ WS_MAXIMIZEBOX, // Non-resizable
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 800,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    if (hwnd == NULL)
    {
        return 0;
    }

    ShowWindow(hwnd, SW_SHOWDEFAULT);

    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}