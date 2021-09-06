// Room: /d/fuzhou/nanmen.c

inherit ROOM;
void quarter_pass();
void create()
{
        set("short", "����");
        set("long", @LONG
�����Ǹ��ݵ����ţ������Ϸ������ͨ����ɽ�򣬿�ϧ���սٷ�������
����������ҹ��ĵ��ŷ��£���׼�κ��˵ȳ��롣�������˻��࣬����������
����æ��
LONG
        );
        set("exits", ([
                "north" : __DIR__"nanjie",
                "south" : __DIR__"birdge",
        ]));
        set("objects", ([
                NPC_D("guanfu/wujiang") : 1,
                NPC_D("guanfu/bing") : 2,
        ]));
        set("outdoors", "����");
	setup();
        quarter_pass();
}

void quarter_pass()
{
        string local;

        local = NATURE_D->query_daytime();

        switch(local){
            case "event_night":
            case "event_midnight":
                  set("long", @LONG
�����Ǹ��ݵ����ţ������Ϸ������ͨ����ɽ�򣬿�ϧ���սٷ�������
��������������ҹ��ʱ�ѵ��ŷ��£���׼�κ��˵ȳ��롣
LONG);
        	  delete("exits/south");
                  break;
            default: set("long", @LONG
�����Ǹ��ݵ����ţ������Ϸ������ͨ����ɽ�򣬿�ϧ���սٷ�������
����������ҹ��ĵ��ŷ��£���׼�κ��˵ȳ��롣�������˻��࣬����������
����æ��
LONG);
                  set("exits/south", __DIR__"bridge");
        	  break;
        }
        call_out("quarter_pass", 60);
}

int valid_leave(object me, string dir)
{
          if (dir =="south" )
        if(present("guan bing", (environment(me)))
        && me->query_condition("killer") > 0)
                return notify_fail("�ٱ����еĵ���ס�����ȥ·��\n");
        return ::valid_leave(me, dir);
}
