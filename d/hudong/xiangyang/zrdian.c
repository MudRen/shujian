// /d/xiangyang/zrdian.c �����
// Lklv 2001.9.24

inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
����һ���������С���ӣ����治��ܴ�һ����������ⰸ�Ӻ��ڵص�
�У����Ӻ���վ��һλ�ֺ����������ˣ����������˸�Χȹ��Χȹ��һȦȦ��
��ӡ������վ�ڰ��Ӻ�����������š�
LONG
        );
        set("xyjob", 1);
        set("exits", ([
                "south" : __DIR__"bcx2",
        ]));

        set("objects", ([
		__DIR__"npc/zhurour" : 1,
        ]));
        set("incity",1);
	setup();
}
