// houyuan.c ��Ժ
// by Lklv

inherit ROOM;
void create()
{
	set("short", "����ׯ��Ժ");
	set("long", @LONG
�����Ǿ���ׯ�ĺ�Ժ��ƽ��û��������Ժ��ѷ��ż��Ѳ�ݡ���ݶ��Ա�
�м���С������ˣ��
LONG );
           set("quest",1);
	set("outdoors", "����");
	set("exits", ([
		"west" : __DIR__"dating",
	]));
	setup();
}
