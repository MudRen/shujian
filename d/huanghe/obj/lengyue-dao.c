// lengyue_dao.c ���±���
#include <ansi.h>
#include <weapon.h>
inherit BLADE;
inherit F_UNIQUE;
#define QUESTDIR5 "quest/ѩɽ�ɺ�/����/"
#define QUESTDIR4 "quest/ѩɽ�ɺ�/�书/"

void create()
{
        set_name( HIB"���±���"NOR , ({ "lengyue dao","lengyue baodao","baodao","lengyue","blade","dao"}));
        set_weight(20000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIB"������ˮ������������ת�������������ý�˿��˿����һ��üë���¡�\n"NOR);
                set("value", 1);
                set("unique", 1);
                set("rigidity", 4);
                set("sharpness", 4);
                set("weapon_prop/parry", 4);
                set("wield_maxneili", 1400);
                set("treasure",1);
                set("wield_str", 24);
                set("material", "steel");
                set("wield_msg", HIB"$N�����鵶���ʣ���ɭɭ��һ����⼤�������գ��֮�䣬�����Ѷ���һ���������˵ĳ�����\n"NOR);
                set("unwield_msg",HIB"$N�����±���С�ĵ�����ҫ�˵ĺ���û�뵶�ʡ�\n"NOR);
        }
        init_blade(120);
        setup();
}
void init()
{
	if (environment()==this_player()&&!this_player()->query_condition("killer"))
	{

		add_action("do_yanjiu",({"yanjiu", "�о�"}));
		add_action("do_guanzhu",({"guanzhu", "��ע"}));
		add_action("do_search",({"search", "Ѱ��"}));
	}
}
int wield()
{
	  object me = environment();
      object ob = this_object();
	  int i=::wield();
          if(clonep() && i &&  objectp(me) && userp(me) && me->query(QUESTDIR4+"hujiadaofa")&&!me->query_temp(QUESTDIR4+"lengquan"))
	  {
     	   message_vision(HIW"\n$N��"+ob->query("name")+HIW"����ͻȻ"+ob->query("name")+HIW"����ҫ�۵İ׹⣡\n"NOR,me);
     	   tell_object(me,HIB"ͻȻ�ӵ�����һ��������˲����о��߽����ȫȻ��ͨһ����\n"NOR);
           me->set_temp(QUESTDIR4+"lengquan",1);
	   }	
	   if(i) return i;
	   else return 0;
}

int unequip()
{
	  object me = environment();
  	  int i=::unequip();
          if(clonep() && objectp(me) && userp(me)  && me->query_temp(QUESTDIR4+"lengquan") && i )
           me->delte_temp(QUESTDIR4+"lengquan");
	   if(i) return i;
	   else return 0;
}
int do_yanjiu(string arg)
{
     	object me, obj;
     	me = this_player();
            obj = this_object();
     	if(me->is_busy()) return 0;
     	if(!me->query(QUESTDIR5+"start")) return 0;
     	if(me->query("neili") < 200)  return notify_fail("������������\n");
     	if(!present("baozang tu",me)) return notify_fail("һ���Ƶ����о�ʲô��\n");
        if( ! arg || (arg != "lengyue baodao"&& arg != "baodao"&& arg != "lengyue"))
                return notify_fail("��Ҫ�о�ʲ�᣿\n");
        if(me->query_temp(QUESTDIR5+"yanjiu_ok"))
     			return notify_fail("���Ѿ����ֵ����ϵ���·������Գ��Զ��ղر�ͼ��\n");
     	if(me->query(QUESTDIR5+"time")&&time()-me->query(QUESTDIR5+"time")<84600)
     			return notify_fail("��о�ȫ����Ѫ���ڣ������ղŵ��о��Ѿ�������ľ���\n");
        if(me->query(QUESTDIR5+"combat_exp")&&me->query("combat_exp")-me->query(QUESTDIR5+"combat_exp")<500000 && !me->query("cw_exp"))
     			return notify_fail("��о�ȫ����Ѫ���ڣ��������㵱ǰ�Ĺ����޷������о���\n");

	   me->start_busy(1);
       message_vision(HIC"$N��"+this_object()->name()+HIC"������ȥ���о��ţ�\n"NOR, me);
       me->add("neili", -150);
       me->add_temp(QUESTDIR5+"yanjiu",1);
      if(me->query_temp(QUESTDIR5+"yanjiu")>6)
      {
      	me->set(QUESTDIR5+"time",time());
      	me->set(QUESTDIR5+"combat_exp",me->query("combat_exp"));
      	tell_object(me,YEL"�㷢��"+obj->name()+YEL"�����Ͽ�����������·���ƺ��Ͳر�ͼ���Զ��ա�\n"NOR);
		tell_object(me,YEL"��о�ȫ����Ѫ���ڣ������ղŵ��о�ֻ���Ѿ�������ľ���\n"NOR);
      	me->set_temp(QUESTDIR5+"yanjiu_ok",1);
      	me->delete_temp(QUESTDIR5+"yanjiu");
      }
     	return 1;
}
int do_guanzhu(string arg)
{
     	object me, obj;
     	string force;
     	
     	me = this_player();
     	obj = this_object();
     	if(me->is_busy()) return 0;
     	if(!me->query(QUESTDIR5+"start")) return 0;
        if( ! arg || (arg != "lengyue baodao"&& arg != "baodao"&& arg != "lengyue"))
                return notify_fail("��Ҫ��ʲ�᣿\n");
        if(me->query_temp(QUESTDIR5+"guanzhu_ok"))
     			return notify_fail("���Ѿ���ע�������������ϵ���·����������\n");
        if(!stringp(force = to_chinese(me->query_skill_mapped("force"))))   
      		return notify_fail("��û�м����ڹ���ι�ע������\n");
     	if(me->query("neili") < 200)  return notify_fail("������������\n");

		message_vision(HIC"$NĬ��"+force+HIC"�������ؽ�������ע��"+obj->name()+HIC"�У�ͻȻ"+obj->name()+HIC"����ҫ�۵İ׹⣡\n"NOR, me);
        tell_object(me,HIY"����ϸ�۲�"+obj->name()+HIY"��������·����������\n"NOR);
     	me->add("max_neili", -10);
     	tell_object(me,HIB"ֻ�ǣ���е���Щ�������ʣ�������ι�ע�Ѿ���������ڹ���Ϊ��\n"NOR);
     	me->set_temp(QUESTDIR5+"guanzhu_ok",1);
	    me->start_busy(2);
     	return 1;
}
int do_search()
{
     object me, obj;
     me = this_player();
     if(!me->query(QUESTDIR5+"start")) return 0;
     if(!present("baozang tu",me)) return 0;
     if(!me->query_temp(QUESTDIR5+"map_where")) return 0;
     if(me->is_busy()) return 0;
     if(me->is_fighting()) return 0;
     if(me->query_temp(QUESTDIR5+"search_ok"))
     	return notify_fail("���Ѿ������ҵ��ر���ַ�ˣ�\n");
     if((string)file_name(environment(me))!=me->query_temp(QUESTDIR5+"map_where")) 
	    return notify_fail(HIW"������"+environment(me)->query("short")+HIW"����һȦ������û�б��أ�\n"NOR);	
     me->start_busy(2);
     if(random(2)) message_vision(HIW"$N����"+environment(me)->query("short")+HIW"������ȥ����ϸ�۲���ʲô��\n"NOR, me);
	 else message_vision(HIW"$N�ƺ�����"+environment(me)->query("short")+HIW"һЩʲô�ر�ĵط�������"+environment(me)->query("short")+HIW"������ȥ��\n"NOR, me);
     me->add_temp(QUESTDIR5+"search",1);

      if(me->query_temp(QUESTDIR5+"search")==4||me->query_temp(QUESTDIR5+"search")==8)
      {
      	me->set(QUESTDIR5+"time",time());
      	me->set(QUESTDIR5+"combat_exp",me->query("combat_exp"));
      	obj=new("/d/xingxiu/baozang/npc/gaoshou");
      	obj->set("kill_id",me->query("id"));
        obj->set("fight_id",me->query("id"));
      	if(me->query_temp(QUESTDIR5+"search")==4) obj->set("title",HIB"�ڷ�կ������"NOR);
      	else obj->set("title",HIB"�ڷ�կկ��"NOR);
      	obj->move(environment(me));
        message_vision(HIC"ͻȻ�ӽ���������һ���ˣ�$n����$N�µ������Ҿ���"+obj->query("title")+HIC"���Ͽ��뿪"+environment(me)->query("short")+HIC"����\n"NOR, me,obj);
      	if(me->query_temp(QUESTDIR5+"search")==8)
      	{
      	    obj=new("/d/xingxiu/baozang/npc/gaoshou");
      	    obj->set("kill_id",me->query("id"));
            obj->set("fight_id",me->query("id"));
      	    obj->set("title",HIB"�ڷ�կ������"NOR);
      	    obj->move(environment(me));      	    
            message_vision(HIC"�����ֳ���һ���ˣ���Ȼ��"+obj->query("title")+HIC"$N���µ����������ϴ�Ļ���û�������С����������\n"NOR, obj);
            log_file("quest/FEIHU", sprintf("%s(%s)Ѱ�ұ��صĹ����������ڷ�կկ��������%d��\n", me->name(1),me->query("id"), me->query("combat_exp")) );
      	}
      }
      if(me->query_temp(QUESTDIR5+"search")==12)
      {
      	me->set(QUESTDIR5+"time",time());
      	me->set(QUESTDIR5+"combat_exp",me->query("combat_exp"));
        tell_object(me,YEL"�㷢��"+environment(me)->query("short")+YEL"�ƺ����Ϻ������Ͽ̵���·��������һ���ߵ�"+environment(me)->query("short")+YEL"��һ�����䡣\n"NOR);
      	message_vision(HIY"$N����ط���һ������ͨ����µ�ͨ����\n"NOR, me);  
        message("channel:rumor", HIW"��ҥ�ԡ�"HIG + "��˵��"+environment(me)->query("short")+HIG"�������ҵ��������صĽ��ڣ�\n"NOR,users() );
        log_file("quest/FEIHU", sprintf("%s(%s)Ѱ�ұ��سɹ�������%d��\n", me->name(1),me->query("id"), me->query("combat_exp")) );
        if( !environment(me)->query("exits/down") ) {
           environment(me)->set("exits/down","/d/xingxiu/baozang/tiantan");
           call_out("close_path", 30,environment(me));
        }
      	me->set_temp(QUESTDIR5+"search_ok",1);
      	me->delete_temp(QUESTDIR5+"search");
      }
     	return 1;
}
void close_path(object ob)
{
        if( !ob->query("exits/down") ) return;
        message("vision",HIR"һ��紵����һ�ж������������ղŵ�һ��������ã�\n"NOR,ob);
        ob->delete("exits/down");
}
