// mushizl.c Ĺ������
// by Lklv 2001.9.27

inherit ROOM;

void create()
{
	set("short", "Ĺ��ͨ��");
	set("long", @LONG
������Ĺ�����һ��ͨ����ǽ���Ϻܳ�ʪ��������ܺڣ�ǰ������������
����ͨ�����Ǻܳ�����һ˿������Զ���չ��������˵�Ӱ���ϵó����ģ�ӡ��
���ϡ�
LONG
       );
	set("exits", ([
		"south" : __DIR__"fenduo2",
		"west" : __DIR__"xmushi",
    	]));
	set("objects", ([
		CLASS_D("gaibang/xqigai") : 1,
	]));
	setup();
}