// /d/fuzhou/wroad.c ɽ·
// Lklv modify 2001.9.10

inherit ROOM;

void quarter_pass();

void create()
{
        set("short","ɽ·");
        set("long",@LONG
�����������һ��ɽ·��ʱֵ���գ�·�Ե�ɽ���ϵ��������˽��ɫ����
�˻���һ����ɽ�紵�����������������Ͳ˻�����ζ��������������븣��
����ɽ����������������С·��
LONG);
	set("outdoors", "����");
	set("exits", ([
                "northwest" : __DIR__"wroad2",
		"east" : __DIR__"ximen",
	]));
	set("no_clean_up", 0);
	setup();
        quarter_pass();
}

void quarter_pass()
{
	string local;
	local = NATURE_D->query_daytime();

	switch(local){
		case "event_night":
		case "event_midnight":
		set("long", @LONG
���Ǹ��ݳ��������һ��ɽ·�����������ϣ����ڳ����Ѿ����ˣ�������
���Ĺ�·��ֻ�ܵȵ��������ܽ����ˡ��ɴ�������븣������ɽ����������
������С·��
LONG);
		delete("exits/east");
		break;
		default: set("long", @LONG
�����������һ��ɽ·��ʱֵ���գ�·�Ե�ɽ���ϵ��������˽��ɫ����
�˻���һ����ɽ�紵�����������������Ͳ˻�����ζ��������������븣��
����ɽ����������������С·��
LONG);
		set("exits/east", __DIR__"ximen");
		break;
	}
	call_out("quarter_pass", 60);
}
