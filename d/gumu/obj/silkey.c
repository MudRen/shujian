#include <ansi.h>;
inherit ITEM;

void create()
{
     set_name(HIW"��Կ��"NOR, ({"yin yaoshi","silver key","key"}));
     set_weight(10);
     if (clonep())
           set_default_object(__FILE__);
     else {
           set("unit", "��");
           set("long", "����һ�Ѱ������Ƶ�Կ�ף������Ĺ�������ƺ��͹�Ĺ��ĳЩ�����йء�\n");
           set("unique", 1);
           set("value", 400);
     }
     setup();
}
