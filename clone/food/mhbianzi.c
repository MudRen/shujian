// by XiaoYao 4/11/99

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("�黨����", ({"mahua bianzi", "mahua", "bianzi"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ���ճ�¯���黨���ӡ�\n");
    set("unit", "��");
    set("value", 120);
    set("food_remaining", 4);
    set("food_supply", 22);
  }
}
