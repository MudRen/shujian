// /u/beyond/hangzhou/yingboqiao.c ӳ����
 
inherit ROOM;
void create()
{
        set("short","ӳ����");
        set("long", @LONG
ӳ���������������࣬�ɹ��ͻ���ɽׯ��ӳ��¥̨ͤ��ǧ��һ�̵���
̶ӳ�£�������ɹ���������ɽ�������䡣�����߾��ǿ���š�
LONG
        );
        set("exits", ([
        "south" : __DIR__"kuahong",
        "east" : __DIR__"sudi",
]));
	set("outdoors", "����");
        setup();
}
