// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Room: /d/changan/duchang3
// by system_3cat 7/5/1997
inherit ROOM;


void create()
{
  set ("short", "��Ժ");
  set ("long", @LONG

������һ����ս�����ż��������Ҳ���Ұ�ݴ����������н�ʬ��û������������


LONG);

  set("item_desc",([
    "paizi" : "Ѻ��ڼ��� dou hg <amount> <money>\n"+ 
              "Ѻ��β���� dou lw <amount> <money>\n", 
  ])); 

  set("exits", ([ /* sizeof() == 1 */
    "west" : __DIR__"chat-dc1",
  ]));

  setup();
}
//�Ǿ���
int is_mirror() { return 1; }