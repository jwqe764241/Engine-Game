#include <Sources/Assets/Pond.h>

void Pond::Load(ID3D10Device * device, int bitmapWidth, int bitmapHeight)
{
}

void Pond::Load(ID3D10Device * device, wchar_t * filePath, int bitmapWidth, int bitmapHeight, int x, int y)
{
	Bitmap.Initialize(device, filePath, bitmapWidth, bitmapHeight);

	Position.x = x;
	Position.y = y;
}

void Pond::Release()
{
	Bitmap.Release();
}

void Pond::Reset()
{
}

void Pond::Update(float dt)
{
}

void Pond::Render(ID3D10Device * device, int screenWidth, int screenHeight)
{
	Bitmap.Render(device, screenWidth, screenHeight, Position.x, Position.y);
}

int Pond::GetIndexCount()
{
	return Bitmap.GetIndexCount();
}

ID3D10ShaderResourceView * Pond::GetTexture()
{
	return Bitmap.GetTexture();
}

D3DXVECTOR2 Pond::GetPosition() const
{
	return Position;
}

void Pond::SetPosition(const D3DXVECTOR2 pos)
{
	Position = pos;
}

void Pond::OnAction(Player * player, float dt)
{
	CoolDown += dt;

	if (CoolDown >= 2.0f)
	{
		player->SetWaterValue(player->GetWaterValue() + 10);
		RefreshCooldown();
	}
}

bool Pond::CheckTool(Player * player)
{
	auto result = std::find_if(player->GetToolList().begin(), player->GetToolList().end(),
		[this](const Tool* p) { return p->GetToolID() == RequiredToolID; });

	return result != player->GetToolList().end();
}

bool Pond::CheckCollision(Player * player)
{
	BitmapSize bitmapSize = Bitmap.GetBitmapSize();
	BitmapSize playerSize = player->GetSprite()->GetBitmapSize();
	D3DXVECTOR2 playerPosition = player->GetPosition();

	return Utils::CheckCollision(
		Utils::RECT_F{ playerPosition.x, playerPosition.y, playerPosition.x + playerSize.width, playerPosition.y + playerSize.height },
		Utils::RECT_F{ Position.x - 20, Position.y - 20, Position.x + bitmapSize.width, Position.y + bitmapSize.height }
	);
}

void Pond::RefreshCooldown()
{
	CoolDown = 0.0;
}