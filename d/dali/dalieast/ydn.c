// Room: /d/dali/ydn.c
// bbb 1997/06/10 
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "��һ��");
	set("long", @LONG
���붴�ڣ�ֻ�����ܵ��ɰ˹�����������·��ʯ��֮�ϣ���̬��Ȼ������
������������ȣ����ݶ�ׯ��վ�ڴ˴����׶��ڣ�һ�òԾ���������������
ʯ���ϣ����Ķ���Ϊ�׸յľ�ʯ�����ƣ�¶����ľ��ӳ�µĵ�һ�졣
LONG
	);
        set("outdoors", "����");

	set("exits", ([
             "down" : __DIR__"ydx",
             "up" : __DIR__"ydk",
	]));

	setup();
}
