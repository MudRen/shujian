// by XiaoYao 4/11/99

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("�ձ�", ({"shao bing", "bing"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ����������ձ���\n");
    set("unit", "��");
    set("value", 200);
    set("food_remaining", 3);
    set("food_supply", 35);
  }
}
