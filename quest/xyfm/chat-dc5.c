inherit ROOM;

void create()
{
  set ("short", "�ĵ�");
  set ("long", @LONG

������һ����ս�����ż��������Ҳ���Ұ�ݴ����������н�ʬ��û������������

LONG);

  set("item_desc",([
    "paizi" : "Ѻ���ٹ꣺ sai cs <amount> <money>\n"+ 
              "Ѻǧ��꣺ sai qn <amount> <money>\n"+ 
              "Ѻ���Ϲ꣺ sai bl <amount> <money>\n", 
  ])); 

  set("exits", ([ /* sizeof() == 1 */
    "north" : __DIR__"chat-dc4",
  ]));
  setup();
}
//�Ǿ���
int is_mirror() { return 1; }