#include <ansi.h>
inherit ITEM;
#define QUESTDIR5 "quest/ѩɽ�ɺ�/����/"
string* map_where = ({"/d/hj/caoyuan1","/d/fairyland/shanxi","/d/lanzhou/qingcheng",
                      "/d/lanzhou/tumenzi","/d/lanzhou/gccheng","/d/lanzhou/wufosi",});  
string* map_name = ({"�ݺ�","����СϪ","���","����������","�ų���","�����",});  

void create()
{
        set_name(HIB"����ͼ"NOR, ({ "baozang tu","tu"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","һ����Ƥֽ���ƺ��������¼һЩɽ���������ͳ���ĵ�ͼ��\n"+
                           "����԰���ͼ�ϵ����Ӷ��գ�duizhao����ķ�λ��\n");
                set("value",1);
                 set("unique", 1);
                set("no_get",1);
                set("no_give",1);
                set("no_drop",1);
        }
        setup();
}

void init()
{
	if (environment()==this_player()&&!this_player()->query_condition("killer"))
	{
        add_action("do_duizhao","duizhao");
  }
}

int do_duizhao(string arg)
{
     	object me, obj,room;
     	int i;
     	string where,name;
     	me = this_player();
     	obj= this_object();
     	if(me->is_busy()) return 0;
     	if(me->is_fighting()) return 0;
     	if(!me->query(QUESTDIR5+"start")) return 0;
     	if(!present("lengyue dao",me)) 
     	    return notify_fail(HIY"�����ĵ�ͼ�޷��ṩ�㹻����Ϣ������Ҫ����������\n"NOR);
        if( ! arg || (arg != "lengyue baodao"&& arg != "baodao"&& arg != "lengyue"))
                 return notify_fail("����յĶ����޷��Ƚϳ�ʲô�����\n");
      if(!me->query_temp(QUESTDIR5+"yanjiu_ok"))
     		  return notify_fail(HIY"�����ĵ�ͼ�޷��ṩ�㹻����Ϣ������Ҫ����������\n"NOR);
      if(!me->query_temp(QUESTDIR5+"guanzhu_ok"))
      {
           message_vision(HIC"$N��"+obj->name()+HIC"�Ա������±�����������ȥ���о��ţ�\n"NOR, me);
     	   me->add("neili", -150);
     	   return notify_fail(HIY"���ź����ǣ������ϵ���ʾ�ƺ�������������\n"NOR);
     	}
      if(me->query_temp(QUESTDIR5+"search_ok"))
     	   return notify_fail(HIY"��ͼ�Ѿ�ʲô�����������ˣ�\n"NOR);
      if(me->query_temp(QUESTDIR5+"map_where"))
     	   return notify_fail(HIY"��ͼ�������ģ����ʲôҲ��������ˣ�\n"NOR);
      i=random(sizeof(map_where));
      where=map_where[i]; 
      name=map_name[i]; 
      if(!room=find_object(where))
        room=load_object(where);
      if(!room)  return notify_fail(HIY"��ͼ�������ģ������������ʦ�����ֽţ�\n"NOR);
     	message_vision(HIC"$N��"+obj->name()+"�Ա������±�����������ȥ���о��ţ�\n"NOR, me);
     	tell_object(me,YEL"�㷢�ֵ����ϵ�������·���ƺ��Ͳر�ͼ���Զ��ա�\n"NOR);
     	tell_object(me,YEL"��ͻȻ�������߽�����յı�־��Ȼ����һ����������Ϥ�ĵط�����"+name+"��\n"NOR);
      me->set_temp(QUESTDIR5+"map_where",where);
      me->start_busy(1);
     	return 1;
}
