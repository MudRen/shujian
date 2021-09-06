#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIC"����"NOR, ({ "bo juan", "bojuan", "book"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�����Ƴ����ʵ�������ͣ���֪��ʲô����֯�ɣ�������ң�������������ؼ���\n"); 
                set("unique", 1);
                set("treasure", 1);
                set("material", "silk");
                set("no_give", "�������������뿪�㡣\n");
                set("no_get", "�������������뿪�Ƕ���\n");
        }
}


void init()
{
             add_action("do_du", "read");
     	      add_action("do_fan", "fan");	
      	      add_action("do_fan", "find");
}

int do_fan(string arg)
{
	object obj,me = this_player();    
    		       
	if (!(arg=="bo juan" || arg == "bojuan" || arg == "book")) return 0;
	if ( me->is_busy()) 
		return notify_fail("��������æ���ء�\n");
	if( me->is_fighting() ) 
		return notify_fail("���޷���ս������������顣\n");
	if (!id(arg))
		return notify_fail("��Ҫ��ʲô��\n");

	if(this_object()->query("owner")!=me->query("id"))
		return notify_fail("���������������������\n");

	if (me->query("quest/�����˲�/�书/pass") && me->query("quest/�����˲�/��ڤ��/pass") )
		return notify_fail("�����������ص����ݶ�����˵�Ѿ���Ȼ�����ˡ�\n");

       if (me->query_temp("find") < 8 ){
              write("�㻺��չ������ֻ��������������Ķ���һЩͼ�κ����֣�������ң���������ص��书�ؼ���\n");
              me->add_temp("find", 1);         
              return 1;
         }
  
write("����ϸ�����Ų��������ǵ���ң����ѧ����ѧ��Ϊ���н�չ��\n");
                 me->set_skill("zhemei-shou",me->query("max_pot"));
                 me->set_skill("liuyang-zhang",me->query("max_pot"));
                 me->set_skill("tianyu-qijian",me->query("max_pot"));
                 me->set_skill("ruyi-dao",me->query("max_pot"));
   if(   (random(me->query("kar"))+random(me->query("int"))) > 30
           && (random(me->query("dex"))+random(me->query("int"))) > 30
           && random(me->query("kar")) <31
           && random(me->query("kar"))> 20 )
  {
	  tell_object(me,HIG"�㷭����󣬲��ɵô�Ϊ��ϲ���ⲿ�ֲ�û�б�˺�ã����š��貨΢�������֡�\n"NOR);
	  tell_object(me,HIG"�������������ӡ��ע�������á������������ȵ������������׾��еķ�λ��\n"NOR);
         tell_object(me,HIG"ֻ����ӡ�������飬��֪�м�ǧ�ٸ�����һ����ӡ����һ����ӡ�������߹ᴮ��\n"NOR);
	  tell_object(me,HIG"���ϻ��м�ͷ������һ�׷����Ĳ��������д��һ���ֵ��������ǿ�У��Դˡ�\n"NOR);
	  tell_object(me,HIG"����������������ȡ������\n"NOR);
	  me->set("quest/�����˲�/�书/pass",1);
         me->set("quest/�����˲�/�书/read", 1);
         me->delete_temp("find");
	  me->start_busy(2);
         me->set_skill("lingbo-weibu",1);
	  log_file("quest/lbwb", sprintf(HIR"%s(%s) ͨ���������ؼ�ѧ���貨΢������Դ��%d�����飺%d��\n"NOR, me->name(1),me->query("id"), me->query("kar"),me->query("combat_exp")) );
  }

 if(   random(me->query("kar"))>20
        && me->query("kar") <31 
        && random(me->query("pur") )>20
        && me->query("pur") <31
      && ( random(5) ==1 ||( me->query("buyvip")&& random(3)==1 ) )
 ) { 
       tell_object(me,HIC"��սս�����Ĵ򿪳���������Ǹ����һ��Ĳ���չ��������\n"+
                        "��һ��д�š���ڤ�񹦡����ּ������������������������\n"+
                        "�ı�����ͬ�����д������ׯ�ӡ���ң�Ρ����ƣ����֮��\n"+
                        "��ڤ���ߣ����Ҳ�������ɣ������ǧ�δ��֪����Ҳ����\n"+
                        "���ƣ����ҷ�ˮ֮��Ҳ�������为����Ҳ����������ˮ����\n"+
                        "��֮�ϣ����Ϊ֮�ۣ��ñ����򽺣�ˮǳ���۴�Ҳ�����ǹʱ�\n"+
                        "���书���Ի�������Ϊ��һҪ�塣�����Ⱥ������书�޲�Ϊ\n"+
                        "�����ã���֮��ڤ������С���޲��أ�����С���޲��ݡ��ǹ�\n"+
                        "����Ϊ��������Ϊĩ��������ͼ������������ϰ����\n\n"NOR);

       me->set("quest/�����˲�/��ڤ��/pass",1);
      if(!me->query_skill("beiming-shengong")) 
                 me->set_skill("beiming-shengong",me->query("max_pot"));
          
          message_vision(HIC"\n��ġ���ڤ�񹦡������ˣ���\n"NOR,me); 
          message_vision(HIC"\n��ٲȻ�Ѳ�͸�˲����е��书��ѧ���Ժ��Ҫ�����Լ���ϰ�ˣ���\n"NOR,me); 
      me->start_busy(2);
      me->set("quest/�����˲�/��ڤ��/time", time());
      me->set("quest/�����˲�/��ڤ��/combat_exp",me->query("combat_exp"));
     if(!me->query_skill("beiming-shengong"))  me->set_skill("beiming-shengong",1);
     log_file("quest/bmsg", sprintf(HIR"%s(%s) ͨ���������ؼ�ѧ�ᱱڤ�񹦡���Դ��%d�����飺%d��\n"NOR, me->name(1),me->query("id"), me->query("kar"),me->query("combat_exp")) );
    }

  else
  {
	  tell_object(me,HIY"\n�㷭������ֲ����Ѿ����ڳ¾ɣ�ʲô���������ˣ�ֻ�����ա��޷�������ѧ��������\n"NOR);
	  log_file("quest/lbwb", sprintf("%s(%s) ��ͼ�Ķ��������ؼ�ʧ�ܡ����飺%d����Դ��%d��\n", me->name(1),me->query("id"), me->query("combat_exp"),me->query("kar")) );
	  tell_room(environment(me),HIY""+me->name()+"����֮��,˳�ֽ������ӵ��˵��¡�\n"NOR, ({}));
	  me->start_busy(2);

  }
message_vision(HIC"\n�㻹�����ģ�ȴ���ֲ�����Ϊ���ڳ¾ɣ��Ѿ���Ϊ�ɻң�������ʶ�ˡ�����\n"NOR,me); 
       destruct(this_object()); 
	return 1;	    

}


