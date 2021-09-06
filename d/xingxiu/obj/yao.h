void init()
{
       	add_action("do_tu", "tu");
       	add_action("do_make", "make");
       	add_action("do_dian", "dian");
       	add_action("do_pour", "pour");
}

int do_make(string arg)
{
       	object fire, me, ob;
       	me = this_player();
     
       	if(!arg || arg != "huoyan") return notify_fail("��Ҫ��ʲô��\n");

	if( me->is_busy() )	return notify_fail("����æ���أ�\n");
       	if(!objectp(fire = present("fire", me)) && me->query("neili") < 500)
               	return notify_fail("������û�л��֣���ô����\n");
       	if(me->query_skill("poison", 1) < 60){
             	message_vision("$N���Ż��۽�$n��ȼ��ð��һ������Ķ��̣�\n",me,this_object());
             	message_vision("$N����һ��������æ��$n����һ�ӣ�ԶԶ���˿�ȥ��\n",me,this_object());
             	this_object()->add_amount(-1);
             	return 1;
       	}
       	if(present("huo yan", environment(me)))
             	return notify_fail("�����Ѿ��л����ˣ���Ҫ��ʲô��\n");
       	if(!fire){
             	me->add("neili", -100);
             	message_vision(HIR"\n$N�����³�һ�����̣�������$n������һ��һ�ף����һ��ȼ��һ�����ܻ��棡\n\n"NOR, me, this_object());
       	}
       	else 	message_vision(HIR"\n$N������$n�û��ӵ�ȼ��Ȼ�������ʹ��һ�ӣ�ȼ����һ�����ܻ��棡\n\n"NOR, me, this_object());    
       	ob = unew("/d/xingxiu/obj/huoyan")->move(environment(me)); 
       	this_object()->add_amount(-1);
       	return 1;        
}

int do_pour(string arg)
{
       	string me, what;
       	object ob;
       	function f;

	if( this_player()->is_busy() )	return notify_fail("����æ���أ�\n");
       	if( !arg
       	||      sscanf(arg, "%s in %s", me, what)!=2
       	||      !id(me) )
        	return notify_fail("�����ʽ: pour <ҩ> in <��Ʒ>��\n");

       	ob = present(what, this_player());
       	if( !ob )
               	return notify_fail("������û��" + what + "����������\n");
       	if( !ob->query("liquid/remaining") )
               	return notify_fail(ob->name() + "��ʲôҲû�У���װЩ��ˮ�����ܻ�ҩ��\n");
       	f = (: call_other, __FILE__, "drink_drug" :);
       	ob->set("liquid/drink_func", bind(f, ob));
       	ob->set("poison", query("poison"));
       	message_vision("��һ���Ц���У�$N��һЩ" + name() + "����" + ob->name() + "ҡ���˼��¡�\n", this_player());
       	add_amount(-1);
       	return 1;
}

int do_tu(string arg)
{
       	string me, what;
       	object ob;
          
        if( this_player()->is_busy() )	return notify_fail("����æ���أ�\n");
       	if( !arg
       	||      sscanf(arg, "%s on %s", me, what)!=2
       	||      !id(me) )
               	return notify_fail("�����ʽ: tu <ҩ> on <����>��\n");

       	ob = present(what, this_player());

       	if( !ob )
               	return notify_fail("������û��" + what + "����������\n");
       	if( !ob->query("weapon_prop") )
               	return notify_fail("ֻ��Ϳ�������ϡ�\n");

       	else return notify_fail("��Ҫ�Ƚ�ҩ�۵�ȼ���С�\n");

       	return 0;       
}

int do_dian(string arg)
{
	object me,ob,ob1;

	if( this_player()->is_busy() )	return notify_fail("����æ���أ�\n");
        ob = this_object();
	me = this_player();
	if(!arg||arg!=ob->query("id"))
		return notify_fail("��Ҫ��ȼʲô������\n");

        if(!objectp(ob1 = present("fire", me)))
               	return notify_fail("����Ҫ�Ҹ����֡�\n");

        message_vision("$N���Ż��۽�$n��ȼ��ð��һ������Ķ��̣�\n",me,ob);
        if(me->query_skill("poison", 1) > 79){
                new(ob->query("drug2"))->move(me);                      
                ob->add_amount(-1);
		return 1;
        }
        else{
                message_vision("$N����һ��������æ��$n����һ�ӣ�ԶԶ���˿�ȥ��\n",me,ob);
                ob->add_amount(-1);
		return 1;
        }
}

int drink_drug(object ob)
{       
       string poison = ob->query("poison");
       this_player()->apply_condition(poison,
               (int)this_player()->query_condition(poison) 
               + random(8));
       return 0;
}
