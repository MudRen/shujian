// By River@SJ 2001/9  

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵ����̣����Ŵ�
��������Ͼ��Ͽ��������������������ǳ����֡���ʱ����������������
�߷ɳ۶���������һ·��������·��������������������֡�
LONG
        );
        set("outdoors", "����");
        set("exits", ([ 
                "southwest" : "/d/group/entry/czeroad3",
                "northeast" : "/d/tanggu/wroad4",
        ]));
	set("objects",([
		__DIR__"npc/dadao" : 1,
	]));

        set("no_clean_up", 0);

        setup();
}
