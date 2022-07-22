
#include "Ball.h"


Ball::Ball(Console&con) : Rectangle()
{
	color = con.rgb_b(0,0,1,0);
	size = Vector(1,1);
	position = Vector(39,12);
	velocity = Vector(0, ((rand()%2)*(-2))+1 );
}


Ball::~Ball(void)
{
}

void Ball::draw(Console &con, int color)
{
	con.SetColor(position.getX(), position.getY(), color);
	con.PrintChar(position.getX(), position.getY(), ' ');
}

void Ball::draw(Console &con)
{
	this->draw(con, color);
}

void Ball::erase(Console &con)
{
	this->draw(con, con.rgb_b(0,0,0,0));
}

void Ball::move(Console&con)
{
		if( position.getX() == 1  )// Bounce from left border
		{
			if (velocity.getY()>0) 
				velocity=Vector(1,1);
			else velocity=Vector(1,-1);
		}
		
		if( position.getX() == 79 ) //Bounce from right border
		{
			if (velocity.getY()>0)
				velocity=Vector(-1,1);
			else velocity=Vector(-1,-1);
		}

	erase(con);
	position += velocity;
	draw(con);
}

bool Ball::IsInTouchWithBar(Bar &bar)
{
	if( (position.getY()-1) == (bar.GetPosition().getY())
						   ||
	    (position.getY()+1) == (bar.GetPosition().getY()) )		
	
		for (int x = 0; x < (bar.GetSize()).getX() ; x++)
			if(position.getX()== ((bar.GetPosition()).getX()+x))
				return 1;
		
		return 0;
}

void Ball::stop(void)
{
	velocity = Vector(0,0);
}

bool Ball::IsOutOfScope() 
{
	return (position.getY() <= 1 || position.getY() >= 23);
}

void Ball::Reposition(int x)
{
	position = Vector (39,12);
	switch (x)
	{
		case 0: velocity = Vector(0, ((rand()%2)*(-2))+1 ); break;
			case 1:	velocity = Vector(0, 1 );	break;
				case 2:	velocity = Vector(0, -1 ); break;
	}
}

void Ball::Shoot(char ch)
{
	switch (ch)
	{
		case 'q': velocity = Vector(-1,-1); break;
		case 'w': velocity = Vector(0,-1); break;
		case 'e': velocity = Vector(1,-1); break;
		case 'r': velocity = Vector((1-rand()%3),1); break;  //Computer player shoots the ball in a random direction.
		default: break;
	}
}

void Ball::move(Console&con, char ch)
{
	erase(con);
	if(ch == 'k')
		position += Vector(-3, 0);
	else if(ch== 'l')
		position += Vector(3,0);
	draw(con);
}

bool Ball::IsInTouchWithBonus(Bonus *bonus)
{
	if( position.getY() == (bonus->GetPosition()).getY() 
						&&
	    position.getX() == (bonus->GetPosition()).getX() )		
					 return 1;
					 return 0;
}

bool Ball::WhoShot()
{
	return velocity.getY() < 0;
}

