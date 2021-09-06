//by tangfeng@SJ 2004

inherit ROOM;
#include <ansi.h>
#define QUESTDIR2 "quest/ѩɽ�ɺ�/����ƪ/"

void create()
{
	set("short", GRN "���ׯ�ſ�" NOR);
	set("long",@long
���������ׯ�Ĵ��ţ����Ⱥ�����Ĵ��ų����ţ��ſ������������һ��
��ɫ���ҡ����ׯ����̨��������������ʯʨ��ֻ���Ž����壬��Ϊ������
long);
  set("outdoors", "����");
	set("exits",([
		"east" : __DIR__"sroad1",
		"west" : __DIR__"qianting",
]));
            set("quest",1);
	set("no_fight", 1);
	setup();
}
int valid_leave(object me, string dir)
{
    if (dir == "west" && !me->query(QUESTDIR2+"start")&& !me->query(QUESTDIR2+"over"))
          return notify_fail(RED"���ׯ���Ѿ���գ��޷���ȥ��\n"NOR);
        if(dir == "west" &&me->query_condition("killer")) 
   		          return notify_fail(RED"���ׯ���Ѿ���գ��޷���ȥ��\n"NOR);
    return ::valid_leave(me, dir);
}

void init()
{
  object me;
  me = this_player();
  if (me->query(QUESTDIR2+"start"))
       me->start_busy(1);
  if (me->query(QUESTDIR2+"start")
     &&me->query_temp(QUESTDIR2+"answer")
	 &&!me->query(QUESTDIR2+"over")
     &&!me->query_temp(QUESTDIR2+"kill")
     &&!me->query_temp(QUESTDIR2+"huyidao"))
  {
     tell_object(me,YEL"ͻȻ���������ׯ�ں��������ˣ�ֻ��һ���������������������������ڼ�ô��������Զ�����á���\n"NOR); 
     tell_object(me,YEL"ֻ������һ��˵����������һλ���ѣ�ˡ���˷��������ز���ʶ�����⻰��ֻ�����ǲ��������Ǵ���\n"NOR);       
     remove_call_out("goqianting");
     call_out("goqianting", 3, me);      
     write(CYN"\n�㲻�ɸе�ʮ�ֺ��棬��ͣ������������������\n"NOR);
  } 
  else
  {  
  remove_call_out("greeting");
  call_out("greeting", 4, me);   
  }
	add_action("do_save", "save");
	add_action("do_quit", "quit");
}
void greeting(object me)
{
    int shen;
  if(!me) return;
   if(!present(me,this_object())) return;
   if(me->query(QUESTDIR2+"start")) return;
   shen = me->query("shen");
  if(shen <0) tell_object(me,HIR"ֻ������һ�����������������������һ��а���������뿪��\n"NOR);
     else tell_object(me,HIR"ֻ������һ���������������������λ�����������뿪��\n"NOR);
}
void goqianting(object me)
{
  if(!me) return;
  if(!present(me,this_object()))
  {
      tell_object(me,HIY"�������뿪���ׯ������˾��ʵ�һĻ��\n"NOR);
        log_file("quest/FEIHU", sprintf("%s(%s)�������ׯ��ȴ�����뿪��ʧ�ܡ�����%d��\n", me->name(1),me->query("id"), me->query("combat_exp")) );
     me->delete_temp(QUESTDIR2+"answer");
    return;
}

     tell_object(me,YEL"\n�������������ֵܡ��������š��������Ǿ�ʶ���ֺ�������ծ���ģ�ȴ�������������˵ʲô���㲻�ɺ�������\n"NOR); 
	   tell_room(environment(me), YEL+me->name()+"���˽�������Ʒ�������ų���ƮƮ������Ծ����ǽ��\n" NOR, ({me}));
           tell_object(me,RED"��һ����Ϣ��ʹ����һέ�ɽ����Ṧ��һ����Խ����ǽ����һ���Ṧ�������������ȷʵ�˵á�\n"NOR);
        log_file("quest/FEIHU", sprintf("%s(%s)�������ׯ������%d��\n", me->name(1),me->query("id"), me->query("combat_exp")) );
	   me->move(__DIR__"qianting");  
}
int do_save()
{
	write("���ﲻ׼���̣�\n");
	return 1;
}
int do_quit()
{
	write("���ﲻ׼�˳���\n");
	return 1;
}

