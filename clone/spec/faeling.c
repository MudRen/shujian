//flowray 2005.6.20
// By Spiderii@ty �������ƣ����������ۼ�̫��̬��
#include <ansi.h>


inherit SPEC; 

void create()
{
	set_name (HIR"��Դ������"NOR, ({ "faeling","ling"}));
	set("long","����һ���һ�Դ�����ķ�����,������������ͽ�("HIY"chengjie"NOR")ɱ��������֡�\n");

	set("unit","��");
	set_weight(100);
	set("value",3000000);
       set("no_give",1);
       set("no_drop",1);	
       set("no_get",1);

	set("degree",1);
	set("flag","spec/faeling");
	set("desc","���������ͽ�ɱ������ˡ�");
        set("credit",100);
	
	setup();
}

void init()
{
	add_action("do_chengjie","chengjie");
  
}

int do_chengjie(string arg)
{
	object where,ob,me=this_player();
	int i,j,last_on = strlen(arg);
	string id1,id2;    
	
	if (!arg)
      		{return notify_fail("��Ҫ�ͽ�˭?\n");}
      	else
      	{
        	while (last_on--) if (arg[last_on] < 'a' || arg[last_on] > 'z')
			{return notify_fail(arg+"��ʲô������\n");break;}
	}
	//�Ӹ�����,��ɱһ�Σ�ֻ�ܸ���1�� By Spiderii@ty
	if(me->query("last_killer")=="�������ܳͽ�")
		{ return notify_fail("�������ܳͽ�,�����˴������˰�\n");}
	

	if(!objectp(ob = LOGIN_D->find_body(arg))) 
		{ return notify_fail("û����������ߡ�\n");}
	
	if(me->query("last_kzf")==arg)
		{ return notify_fail("��������ȸ�״��\n");}
	
	if(!(me->query("last_death_time/"+arg)))
      		{ return notify_fail("��ֻ�ܳͽ�ɱ��������ˡ�\n");}
      	
      	// ׷��ʱ��Ϊһ��
      	if (time()-me->query("last_death_time/"+arg)>86400)
      		{ return notify_fail("���ڲ����������ĳ��������е����˰ɡ�\n");}
      	i=strlen(arg)-1;
      	id1=capitalize(arg);
      	id2=capitalize(arg[0..0]+arg[i..i]);
      	if ((!strsrch(me->query("last_killer"),id1,1)) && (!strsrch(me->query("last_killer"),id2,1)))
      		{ return notify_fail("��ֻ�ܳͽ����ɱ������ˡ�\n");}
      	
      	if (me->query("combat_exp")*1.5>ob->query("combat_exp"))
      		{ return notify_fail("��ô�ܷ��¶�����,�㻹��Ŭ�����Լ���취����ɡ�\n");}
      	
      	if (me->query("combat_exp")>2000000)
      		{ return notify_fail("��ô�ܷ��¶�����,�㻹��Ŭ�����Լ���취����ɡ�\n");}
      	
      	if (ob->query_condition("killer"))
      		{ return notify_fail("�����������ٸ�ͨ����,�㻹������ٳͽ����ɡ�\n");}
      		

	if(!objectp(where = environment(ob)))
		  return notify_fail("����˲�֪����������Ү... :-( \n");
	
	j=2*(ob->query("combat_exp")-me->query("combat_exp"))/me->query("combat_exp");
	j*=30;
	if (j>100) j=600; //�ʵ��ӳ�ʱ��,�ϴ���PK
	if (j<30) j=60;
	
	if (file_name(where) == "/d/wizard/relax") 
	{
		//ob->add_condition("relax", j*3);
		tell_object(me, (string)ob->query("name")+"�������ڳͽ䵱�С�\n");
		//tell_object(ob,"����Ϊ�۳�ǿ�������ٴα���Ͷ��,���ϼ���������"+chinese_number(j)+"���ӵĽ���ʱ�䡣\n");
	}
	else	
	{
		tell_room(where, MAG"�����Ʈ����λ��ò��Ů������"+ob->query("name")+MAG"�ڿն�ȥ�ˡ�\n"NOR, ({ ob }));
		tell_object(ob, MAG"��λ��ò��Ů����������ǰ�������㻺��Ʈ������....\n"NOR);
		tell_object(ob,"����Ϊ�۳�ǿ�����ݱ���Ͷ��,�־�������ؽ������һ�Դ"+chinese_number(j)+"���ӵĴ�����\n");
		ob->apply_condition("relax", j*3);
		ob->move("/d/wizard/relax");
		ob->set("relax_timeout_room", file_name(where));	
		tell_object(me, (string)ob->query("name")+"�ܵ��ͽ�,��ץ�����һ�Դ����"+chinese_number(j)+"���ӡ�\n");
		tell_room(environment(ob), MAG"��λ��Ů����"+ob->name()+MAG"Ʈ������"+ob->name()+MAG"����������\n"NOR, ({ ob }));
		ob->set("startroom", "/d/wizard/relax");
	}
	me->set("last_killer","�������ܳͽ�");
	degree();
	return 1;
}	 
