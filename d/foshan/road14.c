// by xiaoyao

inherit ROOM;
void create()
{
        set("short","�ּ��");
        set("long",@LONG
������һ���ּ�С���������������ѡ�������Ǹ��ݳǵ����ŵ��ţ�����
�Ͽɴ����Ϲ㶫��
LONG);
        set("objects", ([
		__DIR__"obj/hua3": 1,
        ]));
        set("outdoors", "��ɽ");
        set("exits",([ /* sizeof() == 1 */
		"north"      : "/d/fuzhou/bridge",
		"southwest" : "/d/group/entry/fsroad13",
        ]));
	setup();
}
