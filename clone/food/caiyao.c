//Modify By Yanyang@SJ 2001.9.22

inherit ITEM;
inherit F_FOOD;
#include <ansi.h>

string *names = ({
                HIY"������˿"NOR,
                HIY"��������"NOR,
                RED"÷�˿���"NOR,
                HIR"��������"NOR,
                HIM"������˿"NOR,
                HIY"���ͼ�Ƭ"NOR,
                HIW"�峴Ϻ��"NOR,
                RED"�廨����"NOR,
                CYN"��˿Ѭ��"NOR,
                RED"�Ǵ��Ź�"NOR,
                RED"������˿"NOR,
                YEL"������Ϻ"NOR,
                HIY"��Ƥ��Ѽ"NOR,
                HIY"�����ض�"NOR,
                HIW"��������"NOR,
                HIR"���ͷ�Ƭ"NOR,
                MAG"�������"NOR,
                YEL"���ʹ೦"NOR,
                RED"��������"NOR,
                HIG"���㶬��"NOR,
                HIW"��䶹��"NOR,
                HIW"���Ŷ���"NOR,
                YEL"���ʸ���"NOR,
                RED"��������"NOR,
                HIR"ץ���Ｙ"NOR,
                HIY"ƬƤ����"NOR,
                HIY"������Ƭ"NOR,
                HIC"��Ϫ����"NOR,
                HIR"��������"NOR,
                HIR"������"NOR,
                HIG"���ݴ���"NOR,
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

