// miantiao XiaoYao by 4/22/99

inherit ITEM;
inherit F_FOOD;

string *names = ({
                "������˿",
                "��������",
		"÷�˿���",
		"��������",
		"������˿",
		"���ͼ�Ƭ",
		"�峴Ϻ��",
		"�廨����",
		"��˿Ѭ��",
		"�Ǵ��Ź�",
		"������˿",
		"������Ϻ",
		"��Ƥ��Ѽ",
		"�����ض�",
		"��������",
		"������˿",
		"���ͷ�Ƭ",
		"�������",
		"���ʹ೦",
		"��������",
		"���㶬��",
		"��䶹��",
		"���Ŷ���",
		"���ʸ���",
});

void create()
{
  set_name("�������", ({"cai yao", "cai", "food"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ�����˴��ѵĲ��ȡ�\n");
    set("unit", "��");
    set("value", 200);
    set("food_remaining", 5);
    set("food_supply", 35);
  }
}

void init()
{
  if (query("name")=="�������")
    set_name(names[random(sizeof(names))], ({"cai yao","cai","food"}));
  ::init();
}
