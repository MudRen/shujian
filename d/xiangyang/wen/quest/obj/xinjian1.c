// Room: /d/huashan/jinshe/obj/xinjian1.c
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
"\n������֮�������Ե��Ω�ú��ߣ����������Һ��ǣ��������У�
\nҪ��Ҫ����
\n���Һ���֮��
\n����������Һ��ǣ����ڿ����������ھ����ߣ�Ȼ�����ᣬʹ��
\n��ӵ��£����ܳ���֮���� 
\n����֮��
\n�ƶ��в�(move ancheng)���Կ��������ϲ㣬������ѧ�ؼ�����\n"
"\n"NOR);

		set("value", 1000);
		set("material", "paper");
		set("no_drop", "�������������뿪�㡣\n");
                set("no_get", "�������������뿪�Ƕ���\n");
	}
}
