// /d/hmy/baizhang.c

inherit ROOM;

void create()
{
        set("short", "����Ȫ");
	set("long", @LONG
��������һ�������ɳ�����Ȫ��˵��Ҳ�֣�������������ˮɫ����������
�ɽ����������Ȫȴ����ƽ���羵��˿��û�а��������
LONG
        );
	set("resource/water", 1);
        set("no_sleep_room",1);

        set("exits", ([ 
	  "eastup" : __DIR__"yupingpu",
	  "south" : __DIR__"qiangu",
]));
        set("objects", ([
                __DIR__"npc/youke": 1,
]));

        set("outdoors", "��ľ��");

        setup();
}
 
