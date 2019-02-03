//Simple Boss 2.0
//Demonstrates access control under inheritance

#include <iostream>
using namespace std;

class Enemy
{
public:
  Enemy();
  void Attack() const;

protected:
  int m_Damage;
};

Enemy::Enemy():
  m_Damage(10)
{}

void Enemy::Attack() const
{
  cout << "Attack inflicts " << m_Damage << " damage points!\n";
}

class Boss : public Enemy
{
public:
  Boss();
  void SpecialAttack() const;

protected:
  int m_DamageMultiplier;
};

Boss::Boss():
  m_DamageMultiplier(3)
{}

void Boss::SpecialAttack() const
{
  cout << "Special Attack inflicts " << (m_DamageMultiplier * m_Damage);
  cout << " damage points!\n";
}

class MegaBoss : public Boss
{
public:
  void MegaAttack() const;

private:
  const int MEGA_ATTACK_MULTIPLIER = 10;
};

void MegaBoss::MegaAttack() const
{
  // Not clear if the book intends the student to refactor the methods or not;
  // implementing a (MEGA_ATTACK_MULTIPLIER * special attack) rigorously requires
  // branch the `SpecialAttack()` calculation into another method like `SpecialAttackValue()`,
  // which MegaAttack() can use.
  cout << "Special Attack inflicts " << MEGA_ATTACK_MULTIPLIER * m_DamageMultiplier * m_Damage <<
          " damage points!\n";
}

int main()
{
  cout << "Creating an enemy.\n";
  Enemy enemy1;
  enemy1.Attack();

  cout << "\nCreating a boss.\n";
  Boss boss1;
  boss1.Attack();
  boss1.SpecialAttack();

  cout << "\nCreating a mega boss.\n";
  MegaBoss boss2;
  boss2.Attack();
  boss2.SpecialAttack();

  return 0;
}
