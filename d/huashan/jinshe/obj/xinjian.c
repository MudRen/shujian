// Room: /d/huashan/jinshe/obj/xinjian.c
// Date: Look 99/03/25

#include <ansi.h>

inherit ITEM;
void setup()
{}
void create()
{
	set_name( "�ż�", ({ "xin jian", "jian" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",RED
"\n�������Һ����ߣ����Һ��ǣ��������ر������������п���ʱ
\n����������������׵�ͼ���٣����о綾���Գ�̰����ͽ������
\n�ڴ�С�����ڡ��� \n""\n"NOR);
		set("value", 10000000);
		set("material", "paper");
		set("no_drop", "�������������뿪�㡣\n");
              set("no_get", "�������������뿪�Ƕ���\n");
	}
}
