// /u/dubei/miaojiang

inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
�����ѽ����置�ĵ������������˴��Ϊ���ˡ�������Ȼ���ȣ�������
��Ȼ��ʪ��
LONG
        );

        set("exits", ([
                "east" : __DIR__"shandao1",
                "north" : "/d/group/entry/mjshan2",
        ]));
     
      
        set("outdoors", "�置");
        setup();
}
