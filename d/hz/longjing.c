// /u/beyond/hz/longjing.c ����
 
inherit ROOM;
void create()
{
        set("short","����");
        set("long", @LONG
�����������Ϸ����룬���������������ֻ�����ܣ���ľï�ܣ���ʯ��
�룬�羰����������Ϊ������Ȫ֮һ��Ȫˮ�����������󺵲��ݡ�
LONG
        );
        set("exits", ([
            "southeast" : __DIR__"hupao",
            "northwest" : __DIR__"yxsdong2",
                        
]));
        setup();
}
