//ROOM /d/xiakedao/dating.c

inherit ROOM;

int do_push(string arg);
void create()
{
        set("short", "����");
        set("long", @LONG
���ǡ����͵����Ĵ��������ܵ�����ţ�������������һ��
�����硣���ڰ���һ���������ӣ�������������������������º�
�Ӵ�������ȥ����������������
LONG );
//        set("valid_startroom",1);
        set("no_fight","1");
        
        set("exits", ([
                "north" : "/d/xiakedao/shanmen",
"east"  : "/d/xiakedao/shibi",
                
        ]));
        set("objects",([
                "/d/xiangyang/npc/lisi" : 1,
        ]));
        setup();

}

