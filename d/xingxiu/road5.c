inherit ROOM;

void create()
{
        set("short", "���ﳤ��");
        set("long", @LONG
���������ﳤ�ǵļ����ˣ���ǽ�ߴ��ʵ�����治ʱ�������׵�ʿ��
�������߶�Ѳ�ߡ������߱��������ı߹ء������ء�������ͨ����ԭ��;��
�����Ǿ������ִ��̳ǡ�
LONG);
        set("exits", ([
          "east" : __DIR__"fangpan",
          "westdown" : __DIR__"jyge",
        ]));

        set("outdoors", "jyg");

        set("coor/x",-190);
  set("coor/y",70);
   set("coor/z",0);
   setup();
}
