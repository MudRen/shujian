
int do_kill(string arg);
int do_tiao(string arg);

void init()
{
	object room,*ob;
	object me = this_player();
	object here = this_object();
	int i;
	
	::init();
	add_action("do_kill","kill");
	add_action("do_kill","ansuan");
	add_action("do_kill","touxi");
	add_action("do_tiao","tiao");
	
	if(!me) return;
		
	if(userp(me) && !wizardp(me)) {
		if(!room=find_object(OUT_DOWN))
			room=load_object(OUT_DOWN)	;
		ob = all_inventory(here);
		for(i=0;i < sizeof(ob);i++) {
						
			if(ob[i]->query("marry") && me->query("marry") && me->query("marry/id")==ob[i]->query("id")){
				tell_object(me,HIM"�㿴��"+ob[i]->query("name")+"��������һ��������ؿ���"+me->query("gender")=="����"?"��":"��"+"���ǵ�������ôҲ�������˰���\n"NOR );
				tell_object(ob[i],HIM""+me->query("name")+"��������������һ��������ؿ����㣬�ǵ�������ôҲ�������˰���\n"NOR );
				continue;
			}
			
			
			if(userp(ob[i]) && !wizardp(ob[i]) && ob[i] != me) {
				tell_object(me,HIW"��ͻȻ����"+ob[i]->name()+"Ҳ"+W_MSG+",�������һ����\n"NOR);
				message_vision(HIW"$n����$N������$p�����һ������$N���˹���!\n"NOR,me,ob[i]);
				tell_object(ob[i],"������ô���صĵط���ȻҲ�ᱻ���֣��㲻���ֽŴ��ҡ�\n");
				ob[i]->add_busy(1+random(4));
				me->kill_ob(ob[i]);
				ob[i]->kill_ob(me);
				return;
			}
		}
	}
	"/cmds/std/look.c"->look_room(me,here);
}

int do_tiao(string arg)
{
	object me = this_player();
	string msg1,msg2;
	if(me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");
	if(!arg || arg != "down")
		return notify_fail("��Ҫ�����Ķ���\n");
	if (W_MSG=="����ʯ����"){
		msg1 = HIY"$N����һ��������ë������Ʈ��������\n"NOR;
		msg2 = HIY""+me->name()+"��ʯ������������\n"NOR;
	}
	if (W_MSG=="������"){
		msg1 = HIY"$N����һ�ݣ������˵��ϡ�\n"NOR;
		msg2 = HIY""+me->name()+"��������������\n"NOR;
	}
	message_vision(msg1,me);
	me->move(OUT_DOWN);
	message("vision",msg2,OUT_DOWN,me);
	return 1;
}

string look_down()
{
	object room;
	if(!room = find_object(OUT_DOWN))
		room = load_object(OUT_DOWN);
	"/cmds/std/look.c"->look_room(this_player(),room);
	return """";
}

int do_kill(string arg)
{
	object ob,room;
	object me = this_player();
	if(me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");
	if(!arg || !(room = find_object(OUT_DOWN)))
		return notify_fail("��Ҫ͵Ϯ˭��\n");
	if(!(ob = present(arg,room)))
		return notify_fail("��Ҫ͵Ϯ˭��\n");
	if(!ob->is_character() || ob->is_corpse())
		return notify_fail("�����һ�㣡\n");
	if(!userp(ob))
		return notify_fail("͵Ϯnpc? ����\n");
	//if(wiz_level(me) < wiz_level(ob))
		//return notify_fail("�㲻��͵Ϯ��ʦ�ȼ�����ߵĶ��֡�\n");
	message_vision(HIW"$N��ʯ����һԾ���£�������磬ֱȡ"+ob->name()+"��\n"NOR,me);
	message_vision(HIW"��Ȼһ��ɱ��Ϯ����$Ņͷ��ȥ��ֻ��һ����ӰЮ�ž������Ӷ��£���\n"NOR,ob);
	me->move(room);
	if(!random(10)) {
		message_vision(HIY"ȴ��$N����׼������������һ���ù����ƣ��û���$n����������\n"NOR,ob,me);
		me->start_busy(3);
	} else if(!random(5)) {
			message_vision(HIW"$N���һ������æ���������һ����$n��������$N�ıǼ��ӹ���\n"NOR,ob,me);
		} else {
			message_vision(HIR"$Nֻ��һ�������̹ǵ�ɱ��Ϯ���������رܣ��ѱ�$nһ�����У���\n"NOR,ob,me);
			ob->start_busy(4);
			}
	me->kill_ob(ob);
	if(!userp(ob))
		ob->kill_ob(me);
	else {	
		ob->fight_ob(me);
		if(userp(me))
			tell_object(ob,HIR"�����Ҫ��" + me->name() + "�����ಫ������Ҳ���������һ��killָ�\n"NOR);
		}
	return 1; 
}