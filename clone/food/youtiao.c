// by XiaoYao 4/11/99

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("����", ({"you tiao", "youtiao"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ����������ð��������\n");
    set("unit", "��");
    set("value", 180);
    set("food_remaining", 4);
    set("food_supply", 28);
  }
}
