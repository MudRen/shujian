// /u/beyond/hz/yuhuangshan.c ���ɽ
 
inherit ROOM;
void create()
{
        set("short","���ɽ");
        set("long", @LONG
���ɽ��ľ���̣�����ͦ�Σ�ͤ���ڶ࣬�������ƣ�����������������
����Χ��ȫ����ɫ���������Ǿ����£�������͵��˻��ܡ�����������������
LONG
        );
        set("exits", ([
"northwest" : __DIR__"jingcisi",
"southwest" : __DIR__"hupao",
            "south" : __DIR__"zilaidong",
                        
]));
        set("coor/x",100);
  set("coor/y",-350);
   set("coor/z",0);
   setup();
}
