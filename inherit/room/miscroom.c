//by Ciwei@SJ 2004-2-20

#include <ansi.h>
#include <room.h>
#define MISCD "/adm/daemons/miscd"

#define SAVE_VALUE 0.01
inherit ROOM;

int do_show(object me);
int get_value(object me,mapping list);
int get_value2(float savetime,float value);
string money_str2(int v);

void init()
{
	object me = this_player();
	add_action("do_save",	"baocun");
	add_action("do_save",	"cun");
	add_action("do_get",	"tiqu");
	add_action("do_get",	"qu");
	add_action("do_list",	"dlist");
	add_action("do_delete",	"delete");
	add_action("do_delete",	"shanchu");
	if(!query("item_desc/sign"))
	set("item_desc/sign",
        	"
                    �齣���˴����� ȫ������ ʹ��˵��
        ============================================================
                             �� �� ˵ ��
        ------------------------------------------------------------
                       ��ʾ��Ʒ��dlist
                       ������Ʒ��baocun/cun     [��Ʒ��]
                       ��ȡ��Ʒ��tiqu/qu        [��Ʒ��]
                       ɾ����Ʒ��delete/shanchu [��Ʒ��]

        ============================================================
        �۸񹫵���ͯ�����ۣ�"HIR+chinese_number(MISCD->get_days())+"���ڲ���ȡ�Զ�������"NOR"
        	
        �𲽼ۣ�һ��������
                \n",
        );
      if (userp(me) && getuid(me)=="zmud")
	add_action("do_debug", "dd");

}
int do_delete(string arg)
{
	object me = this_player();
	object ob;
	int num = 1;
	string id1,id2,id;
	mapping list;
	int *v,i;
	int f = 1;	
	
	if(me->is_busy() || me->is_fighting()) return notify_fail("����æ���أ�\n");
	if(!arg) return do_show(me);
	if(sscanf(arg,"%s %s %d",id1,id2,num)==3) id = sprintf("%s %s",id1,id2);
	else if(sscanf(arg,"%s %d",id1,num)==2) id = id1;
	else id = arg;//Ps: Ӧ��û��ʲô����id �ĸ�ʽ���� ����ɣ�hehe
	list = MISCD->query_show_list(me,1);
	notify_fail("�㲢û�б������Ʒ��\n");
	v = keys(list);
	if(sizeof(v)==0)
		return 0;	
	for(i=0;i<sizeof(v);i++)
	{
		if( strip(list[v[i]]["name"])==id || list[v[i]]["id"]==id )
		{
			if(f==num) {				
				ob = MISCD->load_this_object(me,list[v[i]]["save_id"],v[i]);	
				if(objectp(ob)) {				
				message_vision(CYN"$N��$n"+CYN"���Լ��ĸ��˴�������ɾ���ˡ�\n"NOR,me,ob);
				destruct(ob);
				me->start_busy(1+random(2));//��ֹbug
				}
				else {return 0;}
				return 1;
			}
			else f++;
		}
	}
	return 0;
}


int do_list(string arg)
{
	object me = this_player();		
	return do_show(me);
}

int do_save(string arg)
{	
	object obj;
	object me = this_player();
	mapping list;
	
	if(me->is_busy() || me->is_fighting()) return notify_fail("����æ�ţ�\n");
	if(!arg) return notify_fail("��Ҫ����ʲô������\n");
	if(!objectp(obj = present(arg, me))) return notify_fail("������û������������\n");
	
	if(me->query_condition("killer")) return notify_fail("�����ڱ��ٸ�ͨ����С��ɲ��ұ��������Ʒ��\n");
	
	notify_fail(obj->name()+"�����Ա����档\n");
	
	if(!clonep(obj)
	||obj->query("unique")
//        ||obj->query("no_get")
//         ||obj->query("no_give")
    ||obj->query("no_cun")
//        ||obj->query("no_drop")
	||obj->query("quest")///////////
	||obj->is_corpse()
	||obj->query("food_remaining")
	||obj->query("liquid")
	||obj->query("material")=="meat"//�⣿
	||obj->query("money_id")
	||strsrch(file_name(obj),"/d/city/weapon/")==0
	||strsrch(file_name(obj),"/clone/weapon/user_weapon_sn")==0
	||obj->is_character()
	||(stringp(obj->query("owner")) && obj->query("owner")!="0")
//         ||obj->query("credit")
	//||obj->query("")
	//||obj->query("")
	//||obj->query("")
	) return 0;	
	//��Ȼ���Ա����κ���Ʒ �����ܵ���Щ����...
	
	if(obj->query("equipped")) return notify_fail("�㻹���Ȱ�"+obj->name()+"�������ɡ�\n");
	
	list = MISCD->query_show_list(me,1);
	if(mapp(list) && sizeof(keys(list))>=MISCD->get_save_num(me)){
		if(me->query("registered")!=3) write(HIG"�������û������ܸ��߱���������\n"NOR);
		return notify_fail("��ĸ��˴����������ˡ�\n");
	}
        if (MISCD->save_this_object(me,obj)) {
        	message_vision(CYN"$N�������ó�һ"+obj->query("unit")+"$n"+CYN"�������Լ��ĸ��˴����䡣\n"NOR,me,obj);
        	obj->move(this_object());
        	destruct(obj);
        	me->start_busy(1+random(2));//��ֹbug
        	return 1;
        }
        //log
        return 0;
}
int do_get(string arg)
{
	object me = this_player();
	object ob;
	int num = 1;
	string id1,id2,id;
	mapping list;	
	int *v,i;
	int f = 1;
	int value;
	
	if(me->is_busy() || me->is_fighting()) return notify_fail("����æ�ţ�\n");
	if(!arg) return do_show(me);
	if(sscanf(arg,"%s %s %d",id1,id2,num)==3) id = sprintf("%s %s",id1,id2);
	else if(sscanf(arg,"%s %d",id1,num)==2) id = id1;
	else id = arg;//Ps: Ӧ��û��ʲô����id �ĸ�ʽ���� ����ɣ�hehe
	list = MISCD->query_show_list(me,1);	
	if(!mapp(list)) return notify_fail("��û�б����κ���Ʒ��\n");
	notify_fail("�㲢û�б������Ʒ��\n");
	v = keys(list);
	if(sizeof(v)==0)
		return 0;	
	for(i=0;i<sizeof(v);i++)
	{
		if( strip(list[v[i]]["name"])==id || list[v[i]]["id"]==id )
		{
			if(f==num) {				
				value = get_value(me,list[v[i]] );				
				if(!me->query("balance")|| value >me->query("balance"))
					return notify_fail("��Ĵ���֧������Ʒ�ı��ܷѡ�\n");
				ob = MISCD->load_this_object(me,list[v[i]]["save_id"],v[i]);	
				if(objectp(ob)) {
				me->add("balance",-1*value);
				message_vision(CYN"$N��$n"+CYN+"�Ӹ��˴���������ȡ������\n"NOR,me,ob);
				tell_object(me,"��Ĵ���п۳���"+MONEY_D->money_str(value)+"��֧�����ܷѡ�\n"NOR);
				ob->move(me);
				me->start_busy(1+random(2));//��ֹbug
				
				//һЩbug��Ʒ�����
				if(strsrch(base_name(ob),"/cmds")==0 )
				{
					message_vision("$Nһ����С�İ�"+ob->name()+"Ū���ˡ�\n",me);
					destruct(ob);
				}
								
				}
				else {return 0;}
				return 1;
			}
			else f++;
		}
	}
	return 0;
}
int do_show(object me)
{
	mapping list;
	int i;
	int *v;
	int savetime;
		
	list = MISCD->query_show_list(me,1);
	v = keys(list);
	if(sizeof(v)<=0){
		write("��û�б����κ���Ʒ��\n");
		return 1;
	}
	
	write(WHT"����ĸ��˴����䱣����("+chinese_number(sizeof(v))+"����Ʒ)��\n"NOR);
	write("��������������������������������������������������������������������������������������������������������������\n");
	write("��       ID             ��  ��               ��  ��               ȡ���踶�ʷ�              ����ʱ��        ��\n");
	/////////12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890	
	write("�ǩ�����������������������������������������������������������������������������������������������������������\n");
	for(i=0;i<sizeof(v);i++)
	{		
		sscanf(list[v[i]]["save_id"],"%*s%ds",savetime);
            write(sprintf("��%|16s%|18s%|24s%|24s%|24s��\n",
		list[v[i]]["id"],
		list[v[i]]["name"],
		money_str2(list[v[i]]["value"]),
		money_str2(get_value(me,list[v[i]])),
		ctime(savetime),
		));
	}
	write("��������������������������������������������������������������������������������������������������������������\n");
	return 1;
}
string money_str2(int v)
{
	string re;
	
	if(!v || v==0) return HIW"һ�Ĳ���"NOR;
	if(!intp(v)) return "";
	re = MONEY_D->money_str(v);
	while(strlen(strip(re))>24)
	{
		if(strsrch(re,"ͭǮ")!=-1){
			if(strsrch(re,"����")!=-1){
				sscanf(re,"%s����%*s",re);
				re = re+"����";
				continue;
			}
			else{
				if(strsrch(re,"�ƽ�")!=-1){
					sscanf(re,"%s�ƽ�%*s",re);
					re = re+"�ƽ�";
					continue;
				}
				else break;
			}
		}
		else if(strsrch(re,"����")!=-1){
			if(strsrch(re,"�ƽ�")!=-1){
				sscanf(re,"%s�ƽ�%*s",re);
				re = re+"�ƽ�";
				continue;
			}
			else break;
		}
		else break;
	}
	return re+NOR;
}

int get_value(object me,mapping list)
{
	float savetime;
	float value;
	int back;
	
	if(!mapp(list)) return 0;
	sscanf(list["save_id"],"%*s%ds",savetime);
	value = list["value"];
	if(!value || value==0) value = 1;
	if( value < 10000) value = 10000;
	savetime = (time()-savetime)/86400;
	if(me->query("registered")==3) savetime = savetime / 20;
	if(!savetime ||savetime==0) savetime = 1;
	back = get_value2(savetime,value);
	if(back<0){
		MISCD->delete_user_item(me,list["save_id"],"���ܷ���Զ���ڻ�Ʒ�����ֵ");
		return 99999999999;
	} //��ֹ����bug hehe
        if(back<100) return 100;
        if(back>100) return 100;
	return back;
}

int get_value2(float savetime,float value)
{
	float back;
	value = value /10000;
	back = savetime*value;
	back = back*SAVE_VALUE;	
	return to_int(back);
}

int do_debug(string arg)
{
	//MISCD->debuging();
	float i,j;
	if (sscanf(arg,"%f %f",i,j)==2)
		write(get_value2(i,j)+"\n");
	return 1;
}
