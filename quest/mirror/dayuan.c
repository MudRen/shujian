// Room: /city/dayuan.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "������Ժ");
	set("long", @LONG
	���߽���Ժ��ӭ����һ����ɽˮ�أ����ϰ���һ�����ι�״��ʯͷ����˵
�ǵ��껨ʯ�ٵ���ʯ��ˮ�ص����������˻��ݡ�������һ�û����������дУ��ڸ�
�˴���Ժ�ӣ��Ե���ɭ�ֲ���һ�������ߵ�ͨ����Ժ���м����Ҷ����ء�
LONG
	);
	set("exits", ([
		"north" : __DIR__"houyuan",
		"south" : __DIR__"caizhu",
	]));
	setup();
}
//�Ǿ���
int is_mirror() { return 1; }