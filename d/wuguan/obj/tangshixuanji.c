
#include <ansi.h>
inherit ITEM;
#include "/d/suzhou/npc/lchj.h";

void create()
{
        set_name(HIG"��ʫѡ��"NOR, ({ "tangshi xuanji", "book","tangshi", "xuanji"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIY"һ������ͨ����ʫѡ����ֻ�Ƿ�����Щ�ƾɡ�\n"NOR); 
                set("unique", 1);
                set("treasure", 1);
                set("material", "silk");
        }
}
void init()
{
        add_action("do_jinpao", "jinpao");
        add_action("do_jinpao", "pour");
        add_action("do_du", "read");
     	add_action("do_fan", "fan");	
     	add_action("do_fan", "find");
	    add_action("do_lingwu", "study");
        add_action("do_lingwu", "lingwu");
}
int do_jinpao(string arg)
{
	string hehe, what;
	object me, ob, obj;
	object *player;
	int i;

	ob = this_object();
	me = this_player();
	player = all_inventory(environment(me));	
	if( !arg ||  sscanf(arg, "%s in %s", hehe, what) != 2 )
		return notify_fail("���jinpao <> in <>\n");

	if(hehe!="book" && hehe!="tangshi xuanji" && hehe!="tangshi" && hehe!="xuanji")
		return notify_fail("��Ҫ������ʫѡ��������\n");

	if( me->is_busy() ) 
		return notify_fail("����æ���ء�\n");
	if( me->is_fighting() )
		return notify_fail("������ս���У�\n");
	if(!me->query(QUESTDIR2+"over")) 
		return notify_fail("���ƺ�ʲôҲ���ֲ��ˡ�\n");
        if(me->query_temp(QUESTDIR2+"find_zi")) 
		return notify_fail("���Ѿ����������е����ܡ�\n");
	if(query("look_zi")) 
		return notify_fail("���Ѿ����������е����ܡ�\n");

	if( !objectp( obj = present(what, me)))  
		return notify_fail("������û��"+what+"����Ҫ�������\n");

	if( !obj->query("liquid/type"))    
		return notify_fail(obj->name()+"��������\n");
	if( obj->query("liquid/type")!="water")    
		return notify_fail(obj->name()+"ʢ�Ĳ���ˮ��\n");
	if( !obj->query("liquid/remaining") )    
		return notify_fail(obj->name() + "�����Ѿ�һ�β�ʣ�ˡ�\n");
	
	for (i = 0; i < sizeof(player); i++) {
				if (living(player[i]) && player[i] != me) 
				{
				   if(me->query("family/master_name")==player[i]->query("family/master_name"))
				       return notify_fail(HIY"����������һ�����ͬ�ŵ���"+player[i]->query("name")+HIY"����Ȼ"+ob->query("name")+HIY"����ʲô��Ʒ���������С��Ϊ�á�\n"NOR);
				   else if(userp(player[i]) && player[i]->query("shen")<0)
				       return notify_fail(HIY"���ﾹȻ��һ������Ľ������"+HIY"��"+ob->query("name")+HIY"��Ȼ����ʲô��Ʒ���������С��Ϊ�á�\n"NOR);
           else if(userp(player[i]))
				       return notify_fail(HIY"����"+player[i]->query("family/master_name")+HIY"�ĵ���"+player[i]->query("name")+HIY"��ȻҲ�����"+ob->query("name")+HIY"��Ȼ����ʲô��Ʒ���������С��Ϊ�á�\n"NOR);
		       else return notify_fail(HIY"����������һ��"+player[i]->query("title")+player[i]->query("name")+HIY"����Ȼ"+ob->query("name")+"����ʲô��Ʒ���������С��Ϊ�á�\n"NOR);
				}
			}         	  	

	message_vision(YEL"$N��ϸ�ؽ��������"+ obj->name() +"�����ˮ֮�С�\n"NOR,me);
	call_out("look_zi",5,me);
	me->start_busy(5);
	obj->add("liquid/remaining", -1);
	return 1;
}
void look_zi(object me)
{

	object ob;
	object *player;
	int i;
	ob = this_object();
	if(!me) return;
	if(query("look_zi")) return;
	player = all_inventory(environment(me));	
	for (i = 0; i < sizeof(player); i++) {
				if (living(player[i]) && player[i] != me) 
				{
				   if(me->query("family/master_name")==player[i]->query("family/master_name"))
				       tell_object(me,HIY"����������һ�����ͬ�ŵ���"+player[i]->query("name")+HIY"����Ȼ"+ob->query("name")+HIY"����ʲô��Ʒ���������С��Ϊ�á�\n"NOR);
				   else if(userp(player[i]) && player[i]->query("shen")<0)
				       tell_object(me,HIY"���ﾹȻ��һ������Ľ������"+HIY"��"+ob->query("name")+HIY"��Ȼ����ʲô��Ʒ���������С��Ϊ�á�\n"NOR);
           else if(userp(player[i]))
				       tell_object(me,HIY"����"+player[i]->query("family/master_name")+HIY"�ĵ���"+player[i]->query("name")+HIY"��ȻҲ�����"+ob->query("name")+HIY"��Ȼ����ʲô��Ʒ���������С��Ϊ�á�\n"NOR);
		       else tell_object(me,HIY"����������һ��"+player[i]->query("title")+player[i]->query("name")+HIY"����Ȼ"+ob->query("name")+"����ʲô��Ʒ���������С��Ϊ�á�\n"NOR);
		       return;
				}
			}         	  	

	message_vision(HIY"\nһ��Ĺ�����ʫѡ���Ͼ�Ȼ��ʾһЩ���ֳ�����$Nȡ��һ֧ͺ�ʣ���һ�Ż�ֽ��д�ˡ���\n"
		             +"����ϡ��ĸ��֣������������š�һ�塢һʮ��ʮ�塢ʮ��������ʮ�����֡���������ֽ��д\n"
					 +"����ƫ���֡�$N��һ���飬��ָ��һ��������дһ���֣�һ��д�˶�ʮ�����֣����ǣ�\n\n"
					 +"��"NOR+HIG"       �������´�������֮��Ĥ��ͨ��ף�������͸���������"NOR+HIY"       ��\n\n"NOR,me);
	set("look_zi",1);
	me->set_temp(QUESTDIR2+"find_zi",1);
	return;
}
	

int do_du(string arg)
{
	object me = this_player();
	if( me->is_busy()) 
		return notify_fail("��������æ���ء�\n");
	if( me->is_fighting() ) 
		return notify_fail("��������æ���ء�\n");
	tell_object(me,YEL"���ж���һ���������ʲô���޷�����ѧϰ����\n"NOR);

	return 1;
}

int do_fan(string arg)
{
 	object me = this_player();
	if( me->is_busy()) 
		return notify_fail("��������æ���ء�\n");
	if( me->is_fighting() ) 
		return notify_fail("��������æ���ء�\n");
	tell_object(me,YEL"�㷭��һ���������ʲô��û�з��֡�\n"NOR);
	return 1;
}

int do_lingwu(string arg)
{
	object me = this_player();
	if( me->is_busy()) 
		return notify_fail("��������æ���ء�\n");
	if( me->is_fighting() ) 
		return notify_fail("��������æ���ء�\n");
	tell_object(me,YEL"���ж���һ���������ʲô���޷�����ѧϰ����\n"NOR);
	return 1;
}
