# SplashWindow
mfc Splash Window+CRgn (visual stdio2019)
https://www.youtube.com/watch?v=eKA8ch6sRXs

起動時にスプラッシュ画面の表示する為のダイアログクラスのh.cppの2つです。
(bmpの輪郭外非表示Paintで透明の選択が必要)
文字は、Paintを使うとぼかしが入るので、にじんだ様に表示されます。

忘れるので使い方メモ。
(1)
リソースビュー,Bitmap,IDB_BITMAP1等を作成。
外部エディターPaintを使いました。透明の選択が必要でした。
(2)
#include "DlgRgn.h"
BOOL 任意App::InitInstance(){
//Rgen+スプラッシュで起動の為追加。
	DlgRgn dlg;
	dlg.DoModal();
}

https://www.codeproject.com/Articles/7658/CSplash-A-Splash-Window-Class
の方が良かったかも？
