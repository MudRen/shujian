// by tangfeng 8/2004

#include <ansi.h>
inherit ITEM;

#define QUESTDIR5 "quest/ѩɽ�ɺ�/����/"
#define QUESTDIR4 "quest/ѩɽ�ɺ�/�书/"

void create()
{
        set_name(HIW"ֽ��"NOR, ({ "zhi tuan", "zhituan", "paper"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ����ֵ�ֽ�ţ�չ��֮���ƺ���¼һЩ�ڹ������з�����\n"); 
                set("unique", 1);
                set("treasure", 1);
                set("material", "silk");
                set("no_give", "�������������뿪�㡣\n");
                set("no_get", "�������������뿪�Ƕ���\n");
        }
}
void init()
{
          if(!this_object()->query("owner")) return;
     	  add_action("do_yanjiu", "yanjiu");	
     	  add_action("do_yanjiu", "find");
}

int do_yanjiu(string arg)
{
	object obj,me = this_player();        		       
	if (!(arg=="zhi tuan" || arg == "zhituan" || arg == "paper")) return 0;
	if ( me->is_busy()) 
		return notify_fail("��������æ���ء�\n");
	if( me->is_fighting() ) 
		return notify_fail("���޷���ս������������顣\n");
	if (!id(arg))
		return notify_fail("��Ҫ��ʲô��\n");
        if( !me->query(QUESTDIR5+"shuku")||me->query(QUESTDIR5+"shuku")<3)
		return notify_fail("�������������ֽ�Ű���\n");
	if(this_object()->query("owner")!=me->query("id"))
		return notify_fail("�������������ֽ�Ű���\n");
	if (me->query(QUESTDIR4+"lengquanshengong"))
		return notify_fail("���Ѿ�������Ȫ�񹦵�����������\n");
  if(!present("tishi ka",me))
  {
  	message_vision(HIY"ͻȻһ����Ӱ������$N��ǰ���ݸ�$Nһ�ſ�Ƭ��\n"NOR, me);
  	tell_object(me,YEL"���ͷһ������һ����ʾ������ͷ��һ������Ӱ�Ѿ�����������˧Ŷ~~~~~��\n"NOR);
  	obj=new(__DIR__"tishika");
  	obj->move(me);
	me->start_busy(2);
    tell_object(me,YEL"�㻹�����濴һ����ʾ�������ݣ���Ҫ���ڳ嶯��\n"NOR);
  	return 1;
  }	
  //ֻ��һ�λ���
  //�Ѷ�ϵ����ԭ�����貨΢���Ѷ���ͬ
  //�����Ѷȣ���ǰ��random(kar)+random(int)>50,�����޸ĳ�1��random(kar+int)>50 by lsxk 2007/9/12
  //����5���Ѷ�,�Ͼ��ǵ���һ��random�ܺ����ж� random (30+30) > 50 ����ж��е���� by server 2007/9/14
  //��Ϊ54, 1/10����
  if((random((int)me->query("kar")+(int)me->query("int"))) > 54
      && !random(3) //�������Ѷ�
  //�����Ѷȣ���ǰ��random(query_con)+random(query_int)>50,�����޸ĳ�1��random(query_con+query_int)>50 by lsxk 2007/9/12
       && (random((int)me->query_con(1)+(int)me->query_int(1))) > 75
	   && me->query("kar")<31)
  {
	  tell_object(me,HIG"��ͻȻ���������ߴ���Ĳ����书�ؼ���ȴ��һ���ر��ĵص㡣\n"NOR);
	  tell_object(me,HIG"����ϸ�о�ֽ�ŵ����ݣ��ص�Ӧ�þ��ڸղž������鷿�\n"NOR);
	  me->set(QUESTDIR4+"lengquanshengong", 1);
	  me->start_busy(2);
	  log_file("quest/FEIHU", sprintf(HIR"%s(%s) �⿪��Ȫ�񹦡���Դ��%d�����飺%d��\n"NOR, me->name(1),me->query("id"), me->query("kar"),me->query("combat_exp")) );
  }
  else
  {
	  tell_object(me,HIY"\n�㰴��ֽ���ϵ���Щ��������ȫ����������ȫ���ô�������˵����书�ˡ�\n"NOR);
	  log_file("quest/FEIHU", sprintf("%s(%s) ��ͼ�⿪��Ȫ��ʧ�ܡ����飺%d����Դ��%d��\n", me->name(1),me->query("id"), me->query("combat_exp"),me->query("kar")) );
	  tell_room(environment(me),HIY""+me->name()+"˳�ֶ���һ��ֽ�š�\n"NOR, ({}));
	  if(me->query(QUESTDIR5+"shuku")==2 && me->query("registered")>=3)
	  {
		  tell_object(me,HIR"\n��ΪVIP��ݣ�����Լ���ʹ�����������ҵ�����һ��ֽ�š���Ҳ�����һ�λ��ᡣ\n"NOR);
		  tell_object(me,HIR"���������ΪĿǰ���Բ��û��������ѣ������Ժ�����������������������˷ѡ�\n"NOR);
	  }
	  me->start_busy(2);
	  destruct(this_object()); 
  }
	return 1;	    
}
