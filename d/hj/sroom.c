// sroom.c ˯��
inherit ROOM;

void create()
{
        set("short", "����������");
        set("long", @LONG
���ǹ��������˾�ס����������������Ƥ�̵أ�����Ҳ���˺�Щ��Ƥţ
Ƥ�������һ���øɲݵ�׵���ë���������һС���衣�����������ƺ�����
�ң���������˾�ЪϢ(sleep)һ�°ɡ�
LONG);

        set("sleep_room", "1");
        set("no_fight", "1");
        set("exits", ([            
              "southeast" : __DIR__"shop",            
        ]));                
        set("coor/x",-330);
  set("coor/y",120);
   set("coor/z",0);
   setup();
}
