inherit ROOM;

void create()
{
        set("short", "���̳�");
        set("long", @LONG
�˳��Ǳ����������ߴ������ݵľ���ֿ⡣�����ڸ߳��Ӵ��������
��Ȼ��̨�ϡ��ʳ����Σ��������ϣ�ճ���������ı��Ѷ��в��ǡ����ſ�
�м����޾���ɵ�ʿ����һ�Ӷ������̶Ӵ�������߹���
LONG);
        set("exits", ([
          "east" : __DIR__"road4",
          "west" : __DIR__"road5",
        ]));

        set("objects", ([
             "/d/city/npc/bing" : 2,
        ]));

        set("outdoors", "jyg");

        set("coor/x",-180);
  set("coor/y",70);
   set("coor/z",0);
   setup();
}