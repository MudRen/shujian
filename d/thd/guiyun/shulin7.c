// /u/jpei/guiyun/shulin7.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long",@LONG
����һƬС���ֵ�����������̲�����ï�ܵ������š���Ҷ�ķ�϶��
ż������һֻС�񱻾�������ʮ�־��š�����ʱ���ж��߳�û����ò�Ҫ��
�˾�����
LONG
);
	set("exits",([
		"south" : __DIR__"shulin5",
	]) );
	set("objects",([
		__DIR__"npc/snake" : 2,
	]));  
	set("no_clean_up",0);
	set("outdoors", "����ׯ");
	setup();
}

