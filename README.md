# cee2015
学部3年の授業で行った組み込み開発関連のもの

いわゆるPBLの授業(学生たちだけでプロジェクトの企画から運営まですべて行う授業)で作成したものです。
FPGA基板で好きなものを作って良いという課題でした。

3人でチームを組み半年間で次のものを作成しました
SDカードに保存された画像をディスプレイに表示するシステムです。

組み込み開発は完全に独学であったため150時間ほど費やしたかと思います。

### 使ったデバイス
* LCD(ファイル名表示)
* SDカードリーダー (ファイルのI/O)
* プッシュボタン (画像の切り替え)
* スライドスイッチ (モードの切り替え)
* 赤外線(IR)リモコン (リモコン制御出来たらなんかかっこいいよねｎ)

### 作った機能
* SDカードからファイルの読み込み
* 画像のレンダリング
* 表示画像の切り替え
* 表示画像の表示モード
  * カラー表示
  * モノクロ表示(この機能に意味はあっただろうか…)
* PNM形式の画像の制御(JPEGは離散コサイン変換必要だったから諦めた)
* ファイル名やファイル情報の表示 (しかも日本語で表示できる。すごい！！)
* チャタリングのソフトウェア制御 (基板にはシュミットトリガ回路が組み込まれているのになんでチャタリングを起こすのだろう…)
* リモコンの制御


### この授業で独習したこと
* アジャイル開発
* 組み込み開発
* プロジェクト運営

### プロジェクトを進めるうえで最初に決めた方針
* 無理難題は人に押し付けない(ラボ畜禁止)
* 時間は有限。チームメンバーそれぞれでこの授業よりも優先すべきことはたくさんある。(出来なかったらそれでいい。死ぬわけではない。)
* 無茶はしない。(病んで死にます)
* よくわからないならとりあえず手を動かす(try and ~~catch~~ error)

### 後からこうしておけばよかったって反省しているところ
* SDカードはサンプルプロジェクトの回路を使うのではなく、QSYSに付属しているSPI回路を使えばよかった。 \
そっちならSDカードリーダーにコマンド制御できるのでSDHCカード or SDXCカードも使えるようになったはず。 \
(今時2GB未満のSDカードなんて売ってないよ…売ってるけど高い…)
 
* VGAでダブルバッファリングやりたかった \
うまくいかなかったけどな！！！

* 漢字ROM作りたかった \
 昔、国民機(PC98)と呼ばれるパソコンがあって日本語を表示するための専用のチップがあったんです。

* FatFS使ってみたかった \
http://irtos.sourceforge.net/FAT32_ChaN/doc/00index_j.html
