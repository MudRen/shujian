// Room: /d/dali/qsjie2.c
// By River 98/12/01
inherit ROOM;

void create()
{
        set("short", "��ʯ��");
        set("long", @LONG
����һ����������ʯ��ֵ������ϱ���ͷ���졣���߸�����һЩ���ӣ���
���Ǵ���ʹ��ˡ��ϱ��Ǳ�ֱ�߾��ܳ��������ţ����治�ϵ����������۶�
����������һ����վ�����в�������������ѡ��ƥ������һ������
LONG
        );
        set("outdoors", "����");

        set("exits", ([ 
                "north" : __DIR__"dlhg/zhengmen",
                "south" : __DIR__"nanjie3",
"east" : __DIR__"yizhan",
                "west" : __DIR__"mafang",
        ]));
 
        set("coor/x",-310);
  set("coor/y",-450);
   set("coor/z",-20);
   set("coor/x",-310);
  set("coor/y",-450);
   set("coor/z",-20);
   setup();
}

