 //      cunluo02.c �������
inherit ROOM;
void create()
{
        set("short","�������");
        set("long",@LONG 
��ǰ�⼸��������û�ˣ��Եþ����ĵأ��������Ƕ���ȥ�ɻ��ˣ������
��·��û���ʡ��������������ţ�����ع���ϡ��������ӣ�����û��С͵ǿ
��ʲô�ġ�Զ�����������ߺ������ţ�����У����ǵ��������Ұɡ�
LONG);
        set("exits",([
                "north" : __DIR__"muchang4",  
                "south" : __DIR__"cunluo1",
                "west" : __DIR__"muchang2",
                "east" : __DIR__"muchang6"
        ]));

        set("coor/x",-200);
  set("coor/y",160);
   set("coor/z",-10);
   setup();
}
