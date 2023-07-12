# minitalk_42tokyo
## 本リポジトリの概要
- UNIXシグナルを使った小さなデータ交換プログラムを実装
  - serverとclientの2つのプログラムを作成しています
  - serverはプロセスIDを確保し、clientからserverに対して文字列を送信します
  - serverはclientから受け取った文字列を表示します（serverはsigintシグナルなどでプログラムを終了しない限りは、待機状態のままになります)

## デモ動画
https://github.com/yugo1906/minitalk_42tokyo/assets/89300571/312965cc-5f38-4c68-a6c3-a6240f7f271f

■動作実行時のコマンドライン引数についての説明
- serverのプログラム
  - 引数なし
- clientのプログラム
  - 第一引数：プロセスID
  - 第二引数：文字列

## 実装の制約
- normというコーディング規約を必ず守ること（for文は禁止、Allmanスタイルで書く、などの様々なルールあり)
- 標準関数は課題で許可されているものしか使用できない

## 雑感
- ターミナルで「man signal」というコマンドをたたくと以下のようなsignalの説明が表示される 
![image](https://github.com/yugo1906/minitalk_42tokyo/assets/89300571/4b0bf179-3114-4f1b-bfd4-0582f1d1f93c)
※SIGUSR1とSIGUSR2はユーザーが動作を定義して利用するシグナルであり、本リポジトリにあるプログラムもSIGUSR1とSIGUSR2を活用している
