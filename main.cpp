#include <Novice.h>

const char kWindowTitle[] = "LC1D_06_シマノ_ユウト_タイトル";

const int blocksize = 32;//プレイヤーの大きさ
const int mapW = 50;//幅
const int mapH = 23;//高さ

struct Box {
	int x;
	int y;
	int w;//幅
	int h;//高さ
};



int Map[mapH][mapW] = {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,},
	{1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,},
	{1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,1,1,1,1,0,1,1,1,0,0,0,1,1,1,1,1,},
	{1,1,1,1,1,0,0,1,0,0,1,1,1,1,1,0,0,0,1,0,0,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,},
	{1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,1,1,1,1,1,},
	{1,0,0,1,0,0,0,0,0,0,1,0,1,0,0,1,1,0,1,1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,0,1,1,1,1,1,1,},
	{1,0,0,1,0,0,0,0,0,0,1,0,1,0,0,1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,1,0,1,0,0,0,1,1,1,1,1,},
	{1,0,0,1,1,0,1,1,1,0,1,0,1,0,0,0,0,1,0,0,0,1,0,1,1,1,1,0,1,1,1,1,0,1,0,0,0,1,1,1,1,1,},
	{1,0,0,1,1,0,0,0,0,0,1,0,1,0,1,0,0,1,0,0,0,1,0,0,0,0,1,0,1,1,1,1,0,1,1,0,0,1,1,1,1,1,},
	{1,0,0,1,1,0,1,0,1,0,1,0,1,0,0,0,0,1,1,1,1,1,0,0,1,0,1,0,1,1,1,0,0,1,0,0,0,0,0,1,1,1,},
	{1,0,0,1,1,0,1,0,1,0,0,0,1,1,0,1,0,1,0,0,0,1,0,0,1,0,1,0,0,0,1,0,0,1,0,0,0,1,0,1,1,1,},
	{1,0,0,1,1,0,1,0,1,0,0,0,0,0,0,1,0,0,0,2,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,},
	{1,0,0,1,1,0,1,0,1,0,0,0,1,0,0,1,1,0,0,0,0,1,0,0,1,0,1,1,1,1,1,1,0,0,0,1,0,1,0,1,1,1,},
	{1,1,0,1,0,0,1,0,1,0,0,0,1,0,0,1,1,1,1,1,0,1,0,0,1,0,1,0,0,0,1,1,0,0,0,0,0,1,0,1,1,1,},
	{1,1,0,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,1,0,0,1,1,1,1,0,1,1,1,},
	{1,0,0,1,0,0,0,0,1,1,1,1,1,1,0,1,0,1,1,1,0,0,1,0,1,0,1,0,1,0,1,1,0,0,0,0,0,1,0,1,1,1,},
	{1,1,0,1,0,0,1,0,1,0,0,0,0,1,0,1,0,1,0,0,0,0,1,0,1,0,0,0,1,0,1,1,0,1,1,1,0,1,0,1,1,1,},
	{1,0,0,0,0,0,1,0,0,0,1,1,1,1,0,1,0,1,0,0,1,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,0,1,1,1,},
	{1,0,1,1,0,0,1,1,1,1,0,0,0,0,0,1,0,1,0,0,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,},
	{1,0,0,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
};


// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	Box Player = { 600,650,17,22 };//22

	/*int playerSpeed = 4;
	int playerSpeedX = 0;
	int playerSpeedY = 0;*/

	int playerLeft = Player.x;//当たり判定の左
	int playerTop = Player.y;//当たり判定の上
	int playerRight = Player.x + Player.w;//当たり判定の右
	int playerBottom = Player.y + Player.h;//当たり判定の下

	int isplayerW = false;
	int isplayerA = false;
	int isplayerS = false;
	int isplayerD = false;

	//ゴールの当たり判定
	int playerLeft2 = Player.x;//当たり判定の左
	int playerTop2 = Player.y;//当たり判定の上
	int playerRight2 = Player.x + Player.w;//当たり判定の右
	int playerBottom2 = Player.y + Player.h;//当たり判定の下


	enum scene
	{
		Title,//タイトル画面
		Setumei,//説明
		game_play,//ゲーム中の画面（背景）
		game_clear,//クリア画面
		game_over//ゲームオーバー画面
	};

	scene scene = Title;//ゲーム最初の画面（タイトル画面）




	//画像の読み込み

	int title = Novice::LoadTexture("./TD3_title.png");//タイトル
	int block = Novice::LoadTexture("./TD3_block.png");//マップのブロック
	int clear = Novice::LoadTexture("./TD3_clear.png");//クリア
	int goal = Novice::LoadTexture("./TD3_goal.png");//ゴール
	int player = Novice::LoadTexture("./TD3_player.png");//プレイヤー
	int setumei = Novice::LoadTexture("./TD3_setumei.png");//説明
	int stage = Novice::LoadTexture("./TD3_stage.png");//ステージ背景


	int playerSpeed = 8;//4
	int playerSpeedX = 0;
	int playerSpeedY = 0;


	int playerSpeedX2 = 0;
	int playerSpeedY2 = 0;

	//各頂点の当たり判定の宣言
	int isHitLeftTop = 0;
	int isHitRightTop = 0;
	int isHitLeftBottom = 0;
	int isHitRightBottom = 0;


	//各頂点の当たり判定の宣言
	int isHitLeftTop2 = 0;
	int isHitRightTop2 = 0;
	int isHitLeftBottom2 = 0;
	int isHitRightBottom2 = 0;

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///





		//switch文（シーン切り替え）

		switch (scene)
		{
		case Title:
			Novice::DrawSprite(0, 0, title, 1, 1, 0.0f, WHITE);
			if (keys[DIK_SPACE] || preKeys[DIK_SPACE])
			{

				scene = Setumei;
			}

			break;

		case Setumei:

			if (scene == Setumei) {
				Novice::DrawSprite(0, 0, setumei, 1, 1, 0.0f, WHITE);

				if (keys[DIK_SPACE]) {

					scene = game_play;

				}
			}

			break;



			case game_play
				:
					if (scene == game_play) {





						Novice::DrawSprite(0, 0, stage, 1, 1, 0.0f, WHITE);



						//マップの描画
						for (int i = 0; i < 23; i++) {
							for (int j = 0; j < 50; j++) {
								if (Map[i][j] == 1)
								{
									/*int x = j * 48;
									int y = i * 48;*/
									/*Novice::DrawSprite(x, y, block, 1, 1, 0.0f, BLACK);*/



									Novice::DrawSprite(int(j * 32), (int)i * 32, block, 1, 1, 0.0f, WHITE);


								}
							}
						}

						/*マップの描画2*/
						for (int i2 = 0; i2 < 23; i2++) {
							for (int j2 = 0; j2 < 50; j2++) {
								if (Map[i2][j2] == 2)
								{
									/*int x = j * 48;
									int y = i * 48;*/
									/*Novice::DrawSprite(x, y, block, 1, 1, 0.0f, BLACK);*/

									Novice::DrawSprite(int(j2 * 32), (int)i2 * 32, goal, 1, 1, 0.0f, WHITE);
								}
							}
						}


						//プレイヤー
						if (playerSpeed > 0) {
							Novice::DrawSprite(Player.x, Player.y, player, 1, 1, 0.0f, WHITE);
							if (Player.x > 1250) {
								Novice::DrawBox(Player.x, Player.y, 22, 22, 0.0f, WHITE, kFillModeSolid);
								//Novice::DrawSprite(Player.x, Player.y, player, 1, 1, 0.0f, WHITE);
								playerSpeed = 0;

							}

						}

						if (Player.x < 30) {
							Novice::DrawSprite(Player.x, Player.y, player, 1, 1, 0.0f, WHITE);
							if (Player.x < 30) {
								Novice::DrawSprite(Player.x, Player.y, player, 1, 1, 0.0f, WHITE);
								playerSpeed = 7;
							}
						}



						//移動速度を求める↓
						if (isplayerW == false && isplayerA == false && isplayerS == false && isplayerD == false) {
							if (preKeys[DIK_W] == 0 && keys[DIK_W] != 0) {
								isplayerW = true;
								playerSpeedY = playerSpeedY - playerSpeed;

							}
						}
						else if (isplayerW == int(true)) {
							playerSpeedY = playerSpeedY - playerSpeed;
						}

						if (isplayerA == false && isplayerS == false && isplayerW == false && isplayerD == false) {
							if (preKeys[DIK_A] == 0 && keys[DIK_A] != 0) {
								isplayerA = true;

							}
						}
						else if (isplayerA == int(true)) {
							playerSpeedX = playerSpeedX - playerSpeed;

						}


						if (isplayerS == false && isplayerW == false && isplayerA == false && isplayerD == false) {
							if (preKeys[DIK_S] == 0 && keys[DIK_S] != 0) {
								isplayerS = true;

							}
						}
						else if (isplayerS == int(true)) {
							playerSpeedY = playerSpeedY + playerSpeed;

						}


						if (isplayerD == false && isplayerS == false && isplayerW == false && isplayerA == false) {
							if (preKeys[DIK_D] == 0 && keys[DIK_D] != 0) {
								isplayerD = true;

							}
						}
						else if (isplayerD == int(true)) {
							playerSpeedX = playerSpeedX + playerSpeed;

						}

						playerLeft = Player.x;//当たり判定の左
						playerTop = Player.y;//当たり判定の上
						playerRight = Player.x + Player.w;//当たり判定の右
						playerBottom = Player.y + Player.h;//当たり判定の下

						//仮にX軸の速度で移動した時の当たり判定
						isHitLeftTop = Map[playerTop / blocksize][(playerLeft + 16 + playerSpeedX) / blocksize] == 1;//4
						isHitRightTop = Map[playerTop / blocksize][(playerRight - 14 + playerSpeedX) / blocksize] == 1;//4
						isHitLeftBottom = Map[playerBottom / blocksize][(playerLeft + 16 + playerSpeedX) / blocksize] == 1;//4
						isHitRightBottom = Map[playerBottom / blocksize][(playerRight - 14 + playerSpeedX) / blocksize] == 1;//4



						//４頂点のどこかに当たったら止まる↓
						if (isHitLeftTop || isHitRightTop || isHitLeftBottom || isHitRightBottom == 1)
						{
							playerSpeedX = 0;
							isplayerW = false;
							isplayerA = false;
							isplayerS = false;
							isplayerD = false;
						}

						Player.x += playerSpeedX;


						//仮にY軸の速度で移動した時の当たり判定
						isHitLeftTop = Map[(playerTop - 11 + playerSpeedY) / blocksize][playerLeft / blocksize] == 1;//4
						isHitRightTop = Map[(playerTop - 11 + playerSpeedY) / blocksize][playerRight / blocksize] == 1;//4
						isHitLeftBottom = Map[(playerBottom - 11 + playerSpeedY) / blocksize][playerLeft / blocksize] == 1;//4
						isHitRightBottom = Map[(playerBottom -11 + playerSpeedY) / blocksize][playerRight / blocksize] == 1;//4

						if (isHitLeftTop || isHitRightTop || isHitLeftBottom || isHitRightBottom == 1)
						{
							playerSpeedY = 0;
							isplayerW = false;
							isplayerA = false;
							isplayerS = false;
							isplayerD = false;
						}

						Player.y += playerSpeedY;

						//4頂点のどこかに当たったら止まる↑




						///↓マップ1のゴールの当たり判定↓///



						playerLeft2 = Player.x;//当たり判定の左
						playerTop2 = Player.y;//当たり判定の上
						playerRight2 = Player.x + Player.w;//当たり判定の右
						playerBottom2 = Player.y + Player.h;//当たり判定の下

						/*仮にX軸の速度で移動した時の当たり判定*/
						isHitLeftTop2 = Map[playerTop2 / blocksize][(playerLeft2 - 4 + playerSpeedX2) / blocksize] == 2;
						isHitRightTop2 = Map[playerTop2 / blocksize][(playerRight2 + playerSpeedX2) / blocksize] == 2;
						isHitLeftBottom2 = Map[playerBottom2 / blocksize][(playerLeft2 - 4 + playerSpeedX2) / blocksize] == 2;
						isHitRightBottom2 = Map[playerBottom2 / blocksize][(playerRight2 + playerSpeedX2) / blocksize] == 2;

						if (isHitLeftTop2 || isHitRightTop2 || isHitLeftBottom2 || isHitRightBottom2 == 2)
						{
							playerSpeedX2 = 0;
							isplayerW = false;
							isplayerA = false;
							isplayerS = false;
							isplayerD = false;

							Player = { 600,650,17,22 };
						}

						Player.x += playerSpeedX2;


						//仮にY軸の速度で移動した時の当たり判定
						isHitLeftTop2 = Map[(playerTop2 + playerSpeedY2) / blocksize][playerLeft2 / blocksize] == 2;
						isHitRightTop2 = Map[(playerTop2 + playerSpeedY2) / blocksize][playerRight2 / blocksize] == 2;
						isHitLeftBottom2 = Map[(playerBottom2 + playerSpeedY2) / blocksize][playerLeft2 / blocksize] == 2;
						isHitRightBottom2 = Map[(playerBottom2 + playerSpeedY2) / blocksize][playerRight2 / blocksize] == 2;

						if (isHitLeftTop2 || isHitRightTop2 || isHitLeftBottom2 || isHitRightBottom2 == 2)
						{
							playerSpeedY2 = 0;
							isplayerW = false;
							isplayerA = false;
							isplayerS = false;
							isplayerD = false;

							Player = { 600,650,17,22 };
						}

						Player.y += playerSpeedY2;

						//↑マップ２の当たり判定(作る場合)//↑
					}





					break;



			case game_clear:
				if (scene == clear) {

					Novice::DrawSprite(0, 0, clear, 1, 1, 0.0f, WHITE);

					if (keys[DIK_SPACE])
					{



						isHitLeftTop = 0;
						isHitRightTop = 0;
						isHitLeftBottom = 0;
						isHitRightBottom = 0;

						isHitLeftTop2 = 0;
						isHitRightTop2 = 0;
						isHitLeftBottom2 = 0;
						isHitRightBottom2 = 0;

						playerSpeedX2 = 0;
						playerSpeedY2 = 0;

						playerSpeed = 8;//4
						playerSpeedX = 0;
						playerSpeedY = 0;
						Player = { 600,650,17,22 };
						scene = Title;
					}
				}







				break;


			case game_over:
				//Novice::DrawSprite(0, 0, over, 1, 1, 0.0f, WHITE);


				if (keys[DIK_SPACE])
				{

					isHitLeftTop = 0;
					isHitRightTop = 0;
					isHitLeftBottom = 0;
					isHitRightBottom = 0;

					isHitLeftTop2 = 0;
					isHitRightTop2 = 0;
					isHitLeftBottom2 = 0;
					isHitRightBottom2 = 0;

					playerSpeedX2 = 0;
					playerSpeedY2 = 0;

					playerSpeed = 8;//4
					playerSpeedX = 0;
					playerSpeedY = 0;


					Player = { 600,650,17,22 };
					scene = Title;

				}



				break;
		}


		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		/*Novice::ScreenPrintf(Player.x, Player.y, 0, 0);*/


		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}

	}
	// ライブラリの終了
	Novice::Finalize();
	return 0;
}