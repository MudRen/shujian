// Room: dayuan.c 
 
inherit ROOM; 
 
void create() 
{
	set("short", "�︮��Ժ");
	set("long", @LONG
����һ���ǳ����Ĵ�Ժ�����߽���Ժ��ӭ����һ����ɽˮ�أ�ˮ�ص���
�������˻��ݡ�һЩѾ�ߺ������ڽ���������æµ�ţ�������Ƿ︮�Ĵ�����
�����Ƿ︮�Ĵ��š�
LONG
	);
	set("exits", ([ 
		"west" : __DIR__"villa-gate",
		"east" : __DIR__"dating",
	]));
	set("outdoors", "��ɽ");
	setup();
}
