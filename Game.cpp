System::Void PharmacyDB::Game::Game_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
	//MessageBox::Show(e->KeyValue.ToString());
	int left_arrow = 37;
	int top_arrow = 38;
	int right_arrow = 39;
	int bottom_arrow = 40;
System::Void PharmacyDB::Game::Game_Shown(System::Object^ sender, System::EventArgs^ e)
{
	this->Width = _width + 200;
	this->Height = _height + 100;
	dirX = 1; //по умолчанию движение по Х вправо есть
	dirY = 0; //по умолчанию движение по Y нет
	_generateMap();
	_generateFruit();
	this->timer->Tick += gcnew EventHandler(this, &PharmacyDB::Game::_update);

	SnakePB = gcnew array <PictureBox^>(400);//определяем максимально возможное кол-во квадратиков (тела змейки)
	SnakePB[0] = gcnew System::Windows::Forms::PictureBox();//создаём голову
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(SnakePB[0])->BeginInit());
	SnakePB[0]->Location = System::Drawing::Point(201, 201);
	SnakePB[0]->Size = Drawing::Size(_sizeOfSides-1, _sizeOfSides-1);
	SnakePB[0]->BackColor = BackColor.LimeGreen;
	this->Controls->Add(SnakePB[0]);

System::Void PharmacyDB::Game::_generateFruit()
{
	fruit->BackColor = System::Drawing::Color::Transparent;
	Bitmap^ image1 = gcnew Bitmap("yellow-fruit.png");
	fruit->BackgroundImage = image1;
	fruit->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
	fruit->Size = Drawing::Size(_sizeOfSides - 1, _sizeOfSides - 1);
	Random^ randomNumber = gcnew Random();

	rI = randomNumber->Next(shift, _height - _sizeOfSides + shift);
	int tempI = rI % _sizeOfSides;
	rI -= tempI;
	rJ = randomNumber->Next(shift, _height - _sizeOfSides + shift);
	int tempJ = rJ % _sizeOfSides;
	rJ -= tempJ;
	rJ++;
	rI++;
	fruit->Location = Point(rI, rJ);
	this->Controls->Add(fruit);
	return System::Void();
}

System::Void PharmacyDB::Game::_MoveSnake()
{
	for (int i = score; i >= 1; i--) {
		//
		SnakePB[i]->Location = SnakePB[i-1]->Location;
	}
	SnakePB[0]->Location = Point(SnakePB[0]->Location.X + dirX * _sizeOfSides, SnakePB[0]->Location.Y + dirY * _sizeOfSides);
	
	_eatItSelf();
}

System::Void PharmacyDB::Game::_eatItSelf()
{
	for (int _i = 1; _i < score; _i++) {
		if (SnakePB[0]->Location == SnakePB[_i]->Location)
		{
			for (int _j = 1; _j <= score; _j++) {
				this->Controls->Remove(SnakePB[_j]);
			}
			this->timer->Stop();
			saveScore(score);
			MessageBox::Show("Результат игры: " + score + " !");
			score = 0;
		}
	}
	return System::Void();
}
