// jiangbian.c
// By Jpei

inherit ROOM;

void create()
{
        set("short", "����");
        set("long",@long
�����������ܶ𽭡��ഫ���͵�ʱ��������һ�����ߣ����в��죬�����
�����������գ��������У��齭��������Ů��ʮ���꣬�ƽ��������ҹ����
�벨�С������գ�����֮ʬ���ڽ��棬������֮���ߣ�������
long);
	set("outdoors", "����");
	set("exits",([
		"northeast" : "/d/group/entry/sztulu2",
		"south" : __DIR__"caoebei",
	]));
	setup();
}
