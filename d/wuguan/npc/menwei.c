// lane@ln 2004.7.13 add party job
#include <ansi.h>
#include <command.h>

inherit NPC;
#include <mudlib.h>

string ask_me();
string ask_help();
string ask_give();
string ask_road();
string ask_lead();
string ask_xin();
string ask_yuebing();
int sort_file(string file)
{
        int i;
        if( file[<2..<1] != ".c" ) return 0;
        if( !sscanf(file, "%*s.c") )  return 0;
        if( sscanf(file, "%*s_noshow.c") )  return 0;
        i = strlen(file);
        while(i--){
                if( file[i] == '.' ) continue;
                if( file[i] < 'a' || file[i] > 'z' )
                        return 0;
        }

        return 1;
}
void create()
{
        int age = 20 + random(20);
        set_name("�������", ({ "men wei", "menwei", "wei" }));
        set("gender", "����");
        set("age", age);
        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set("apply/attack", 30);
        set("apply/defense", 30);
        set("apply/damage", 35);
        set("combat_exp", 150+age*10);
        set("shen_type", 1);

        set("inquiry", ([
                "�����"        : (: ask_yuebing :),
                "��������"      : (: ask_yuebing :),
                "����"          : (: ask_yuebing :),
                "�±�"          : HIY"�Թ�������������������ҹ���塣һ��������������ĺ�����Ծˮ����"NOR,
                "����"          : (: ask_help :),
                "����"          : (: ask_give :),
                "��·"          : (: ask_road :),
                "�ż�"          : (: ask_xin :),
                "�ż�"          : (: ask_xin :),
                "��"            : (: ask_xin :),
                "letter"        : (: ask_xin :),
                "xin"           : (: ask_xin :),
        ]));

        setup();
        add_money("silver", 3+age/10);
        carry_object(ARMOR_D("cloth"))->wear();
}

string ask_yuebing()
{
        object obj,me = this_player();
		int i;
		if(time()<1096300800 && !wizardp(me))
		{
			command("ah");
			command("say ��ô����������𡭡�����Ҫ����"+CHINESE_D->chinese_time(1096300800-time())+"��ʱ��ΰ���");
			command("say ");
			me->start_busy(1);
			return "����Ҫ�ǹ�����ɱ����Ǹ��ϰ������͸������ʺ򰡡��������֪����Ů���ӡ���";
		}
		if(time()>1097164800&& !wizardp(me))
		{
			command("?");
			command("say");
			command("pat "+me->query("id"));
			me->start_busy(1);
			return "��������Ѿ���ȥ�˰ɣ�����";
		}

        if( (me->query("quest/gift/mid-autumn/yuebing")>=8 && me->query("registered")<3)
			||(me->query("quest/gift/mid-autumn/yuebing")>=15 && me->query("registered")>=3))
		{
			command("pat "+me->query("id"));
			return RANK_D->query_respect(me) +"���±����깩Ӧ�����ˣ�";
		}

		if (me->query("mud_age") < (time() - me->query("birthday"))/20 && me->query("registered")<3) {
			if (me->query("online_total") < 3600) {
				CHANNEL_D->do_channel(this_object(), "rumor", me->query("name")+"("+capitalize(me->query("id"))+")��ƭȡ�������ͼ��ϵͳʶ���ˡ�");
				me->set("quest/gift/mid-autumn/yuebing", 8);//ֱ�ӽ�������
				tell_object(me,HIR"��ʧȥ�˻�������Ȩ����\n"NOR);
			}
			command("pat "+me->query("id"));
			return "�ú�Ŭ��Ŷ~~~~~~�´θ���һ�������±�~~~~~~~~";
		}
		/*
		��ͨ��ң�ֻ��Ҫ8�������15����
		�±����ܸ������á�
		*/

        if(me->query("registered")<3)
			i=8-me->query("quest/gift/mid-autumn/yuebing");
		else i=15-me->query("quest/gift/mid-autumn/yuebing");
		if(present("xue yuebing",me))
		{
			command("pat "+me->query("id"));
			command("say "+HIC"��������һ�����������Ҫ�������ˣ��㻹��"+chinese_number(i)+"�λ�������ѯ�ʡ�"NOR);
			command("say �±���ò���ֱ��ʳ�ã�����Գ���ȥ���ǵ���˵������ʲô�ô�......");
			command("hehe "+me->query("id"));
			return HIR"���⣬�����ﰡ���ɱ����Ǹ��ϰ������͸������ʺ򰡡��������֪����Ů���ӡ���"NOR;
		}

		obj=new("/clone/food/yuebing");
		obj->set_name(WHT"ѩ�±�"NOR, ({ "xue yuebing", "yue bing", "yuebing" }));
		obj->set("no_eat",1);//û�õģ��ٺ�
		obj->set("no_sell",1);
		obj->set("no_give",1);
		obj->set("no_drop",1);
		obj->set("no_get",1);
		obj->set("festival","mid-autumn");
		obj->set("owner",me->query("id"));
        obj->set("long","�й���������ڳ��±���һ����ͳϰ�ߣ���ζ���±����ƾ�ϸ��������塣\n"
			         +"\n������±���Щ��֣���Ȼ��״����С���������죬���������а˸�С�֣�\n"
			           +HIR"                    ���齣��Ʒ������ͨ�á�\n"NOR);
        command("smile "+me->query("id"));
        command("say "+HIY"�Թ�������������������ҹ���塣һ��������������ĺ�����Ծˮ����"NOR);
        command("pat "+me->query("id"));
        command("say �����Ĵ�����������Ҳ������������±�������ǵ�����������ѩ�±���Ҳ�����á���");
		obj->move(me);
		message_vision("$N����$nһ��"NOR+WHT"ѩ�±�"NOR+"��\n" NOR, this_object(), me );
		me->add("quest/gift/mid-autumn/yuebing",1);
		if(me->query("registered")<3)
			log_file("quest/yuebing", sprintf("%s(%s)�쵽��%d���±�����VIP��\n", me->name(1),me->query("id"),me->query("quest/gift/mid-autumn/yuebing")) );
		else
			log_file("quest/yuebing", sprintf("%s(%s)�쵽��%d���±���VIP��\n", me->name(1),me->query("id"),me->query("quest/gift/mid-autumn/yuebing")) );

        return HIR"���������ﰡ���ɱ����Ǹ��ϰ������͸������ʺ򰡡��������֪����Ů���ӡ���"NOR;
}

string ask_road()
{
        object me = this_player();

        if( me->query("combat_exp") > 30000 ) {
		return RANK_D->query_respect(me)+ "���书�Ѿ����ͣ���·һ������Ͳ��������ˣ�";
        }

        if( me->query("combat_exp") < 1000 ) {
                return RANK_D->query_respect(me)+"���书̫���ˣ����ǵ�����һ���ٳ��Űɣ�";
        }

        if( me->query_temp( "wg_help" ))
                return "�㲻����������������";

        if( me->query_temp( "wg_road" ) == 1)
                return "�㲻���Ѿ��ʹ�����" ;

        if( me->query_temp( "wg_road" ) == 2)
                return "�㲻�������˴���ȥ" + me->query_temp( "wg_go" ) + "��";

        if( me->query_temp( "wg_go"))
                return "�㲻�������˴�·��\n";
        
        if( me->query( "wg_help_exp" ) && me->query( "wg_help_exp" ) 
                - me->query( "combat_exp" ) > - 2000 )
                return RANK_D->query_respect( me ) 
                + "Ϊ��Ӧ��������ǿ����ô�����������˰�æ�أ�";
        
        me->set_temp("wg_road", 1);
        
        return "��֪" + RANK_D->query_respect(me)+ "Ҫȥ����("HIY"qu <������>"CYN")��";
}

int do_go(string str)
{
        object me = this_player();

        if( me->query_temp("wg_road") != 1 )
                return 0;

        if( !str || str == "" ) {
                write( "��Ҫȥ���\n" );
                return 1;
        }

        message_vision( sprintf( CYN "$N�������������ʩ�˸���" + RANK_D->query_self(me)
                + "����ǰȥ" + str + "��������λ" + RANK_D->query_respect( this_object() )
                + "��æ��\n\n" NOR ), me );

        if( str == "����" || str == "�䵱" || str == "��ü" || str == "����"
                || str == "����" || str == "��ɽ" || str == "ؤ��" || str == "Ľ��"
                || str == "����" || str == "����ׯ" || str == "������" || str == "������") {
                message_vision( sprintf( CYN "���������" + RANK_D->query_respect(me) + 
                        "���ĵȴ�Ƭ�̣����Ŷ�����������������\n\n" NOR), me);
                message( "channel:chat", HIC "�����ġ��������(Men Wei)��" + me->query("name") +
                        "������Ҫ������·ǰȥ" + str + "����֪��λ�ú�Ը���æ��\n" NOR, users() );
                call_out( "remove_effect", 180, me );
                me->set_temp( "wg_road", 2 );
                me->set_temp( "wg_go", str );
                return 1;
        }
        else if( str == "��Ĺ" )
        {
                command( "say ��Ĺ�ڻ����ܲ������˲������룬" + RANK_D->query_respect( me ) 
                        + "�����Լ�ǰȥ�ĺã�\n" );
                return 1;
        }
        else if( str == "����" )
        {
                command( "laugh " + me->query("id") );
                command( "say �����ڲ�������������" );
                command( "fat " + me->query("id"));
                return 1;
        }
        else {
                command( "say  ��ֻ�ܽ�����ǰȥ���֡��䵱����ü�����̡����ޡ���ɽ��"
                        + "��Ĺ��ؤ�Ľ�ݡ���������ׯ�������¡���������\n" );
                return 1;
        }

}

void remove_lead( object me, object ob2 )
{
        if( !ob2 )
                return;

        if( ob2->query_temp( "wg_go" ) )
        {
                message_vision( HIY"ͻȻ���Ա����һ����ݵ��ӣ���$N˵����"
                        + RANK_D->query_respect( ob2 ) + "��ô��û�е�" + ob2->query_temp("wg_go" )
                        + "���ҿ����ǻ�ȥ�����Ҹ��˰�æ�ɡ�\n"NOR, ob2);
                if( me )
                        message_vision( HIY"ͻȻ���Ա����һ����ݵ��ӣ�����$N�ߺߵ�������ô����"
                        + "������Ҫô�����������ˡ�\n"NOR, me);
                ob2->delete_temp( "wg_go" );
        }
        return;
}

string ask_give()
{
        object me = this_player();

	if( me->query_temp( "wg_help" ) )
        {
                command("kick " + me->query("id"));             
                return "��Ҫ�������������˾�����" ;
        }

        if( me->query("combat_exp") < 100000 )
        {
                command("smile " + me->query("id"));
                return  RANK_D->query_respect(me) + "Ҳ���ڳɳ��׶Σ����������Լ��ðɡ�";
        }
        
        me->set_temp("wg_juanzeng",1);
        return RANK_D->query_respect(me) + "���д��ģ��������(juanzeng)�ƽ�ʮ������Σ�";
}

string ask_help()
{
        object me = this_player();

        if( me->query("combat_exp")>30000 )
        {
                return RANK_D->query_respect(me) + 
                        "���书�Ѿ����ͣ����ǿ��Լ���˫��ȥ��Ǯ�ɣ�";
        }
        if( me->query("combat_exp")<1000 )
        {
                return RANK_D->query_respect(me) + 
                        "����û���죬���Ʋ�������Ը�������㣬���ǹ����������ɣ�";
        }
        if( me->query_temp( "wg_road" ) || me->query_temp("wg_go" ))
                return "�㲻���������˴�·��";

        if( me->query_temp( "wg_help" ))
                return "�㲻���Ѿ��ʹ�����" ;

        if( me->query( "wg_help_exp" ) && me->query( "wg_help_exp" ) 
                - me->query( "combat_exp" ) > - 2000 )
                return RANK_D->query_respect( me ) 
                + "Ϊ��Ӧ��������ǿ����ô�����������˰�æ�أ�";

        me->set_temp("wg_help", 1);
        call_out( "remove_effect", 180, me );
        message( "channel:chat", HIC"�����ġ��������(Men Wei)��" + me->query("name") +
                "������Ҫ��������֪��λ�ú�Ը�⿶�����ң�\n" NOR, users() );
        return RANK_D->query_respect(me) + 
                "���ĵȴ�Ƭ�̣����Ŷ�����������������";
}

void remove_effect( object me )
{
        if( !me || environment(me) != environment() ) 
                return;

        if( me->query_temp( "wg_help" ) )
        {
                me->delete_temp("wg_help");
                message_vision( sprintf(HIR "�������ʧ���ض�$N˵����" + RANK_D->query_respect(me)
                        + "�������ǲ�����������æ�ˣ����ǿ��Լ�Ŭ���ɡ�\n" NOR), me );
        }

        if( me->query_temp( "wg_road" ) == 2 )
        {
                me->delete_temp("wg_road");
                me->delete_temp("wg_go");
                message_vision( sprintf(HIR "�������ʧ���ض�$N˵����" + RANK_D->query_respect(me)
                        + "�������ǲ�����������æ�ˣ����ǿ��Լ�Ŭ���ɡ�\n" NOR), me );
        }
        return;
}

void init()
{
        object me, ob, target, *list;
        int i;

        me = this_player();
        ob = this_object();

	::init();

	if( !ob->query_temp("job_party") ) {
		remove_call_out("test_job");
		call_out("test_job", 1, ob);
	} else {
		if( wizardp(me) ) tell_object(me, HIY"�������У�"+ob->query_temp("job_party")+"�Ρ�\n"NOR);
		list = filter_array(users(), (:
			   $1->query("combat_exp") >=100000
			&& $1->query("family/family_name")
			&& !wizardp($1) :));
		i = sizeof(list);
		if( i > 0 ) target = list[(random(i))];
		if( i > 100 ) i = 100;
		if( ob->query_temp("job_party") >= (100 - i/3) && i > 1 ) {
			if( wizardp(me) ) tell_object(me, HIR"��ʼִ�С�\n"NOR);
			ob->delete_temp("job_party");
			if( target ) {
				if( wizardp(me) ) tell_object(me, YEL"����"+target->name()+"("+target->query("id")+")\n"NOR);
                                call_out("do_job", 1, target, me);
			}
		}
	}

        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }

        if( interactive(me) ) 
        {
                add_action( "do_give", "juanzeng" );
                add_action( "do_go", "qu" );
                add_action( "do_lead", "lead" );
        }
        
        return;
}

int do_give( string str )
{
        object me = this_player();
        object ob1,ob2;
        object ob3, ob4;
        object ob5;
        int exp,pot,shen;

        if( !me->query_temp( "wg_juanzeng" ) )
        {
                return 0;
        }

        if (!str || str=="") return notify_fail ("���������˭��\n");
        
        if (!ob1 = find_living(str))
                ob1 = LOGIN_D->find_body(str);
        if (ob1 == me) 
                return notify_fail("�������Լ���\n");
        if(!objectp(ob2 = present(str, environment(me))) )
                return notify_fail("����û " + str + " ����ˡ�\n");
        if( !living(ob2) ) 
                return notify_fail("���" + ob1->name() + "������˵�ɡ�\n");            

        if (!userp(ob2) ) 
                return notify_fail("��ֻ�ܾ�������ҡ�\n");

        if( !ob2->query_temp("wg_help"))
                return notify_fail( "�Է�����Ҫ������\n" );

        if( query_ip_number(me) == query_ip_number(ob2) )
        {
                command( "say ��λ����һ��ֱ�Ӹ�Ǯ���ǣ��ֺα��������أ�\n" );
                command( "admit " + me->query("id") );
                command( "admit " + ob2->query("id" ) );
                return 1;
        }

        ob3 = present( "gold", me );
        if(!ob3)
                return notify_fail( "������û�лƽ�\n" );
        if( ob3 -> query_amount() < 10 )
                return notify_fail( "������û����ô��Ļƽ�\n" );


        ob3->set_amount( ob3->query_amount() - 10 );
        ob4 = present( "gold", ob2 );
        if( !ob4 )
        {
                ob5 = new( "/clone/money/gold" );
                ob5->set_amount( 10 );
                ob5->move( ob2 );
        }
        else
        {
                ob4->set_amount( ob4->query_amount() + 10 );
        }
     
        
        message_vision( sprintf( "$N��$nһЩ�ƽ�\n" ), me, ob1 );
        command( "thank " + me->query("id") );

        exp = 100 + random( 100 ) + random( me->query( "combat_exp" ) / 30000 ) ;
        if( exp > 250 )
                exp = 200 + random( 50 );
        pot = 50 + random( 50 ) + random( me->query( "combat_exp" ) / 60000 ) ;
        shen = 200 + random( 2 * exp );

        write( sprintf( "��õ���" + CHINESE_D->chinese_number( exp ) 
                + "��ʵս�����" 
                //+ CHINESE_D->chinese_number( pot )
                //+ "��Ǳ�ܺ�" 
                + CHINESE_D->chinese_number( shen ) + "������\n" ));

        me->add( "combat_exp", exp );
        me->add( "shen", shen );
//      me->add( "potential", pot );

        log_file("job/newbie", sprintf("%8s%-10s����%8s%-10s���õ�%d�㾭�飬�־���%d��\n",
		me->query("name"), "("+me->query("id")+")",
                ob1->query("name"), "("+ob1->query("id")+")", exp, me->query("combat_exp")), me);

        me->delete_temp( "wg_juanzeng" );
        ob1->delete_temp( "wg_help" );
        ob1->set( "wg_help_exp", ob1->query("combat_exp") );
        return 1;
}

int do_lead( string str )
{
        object me = this_player();
        object ob1,ob2;

        if (!str || str=="")
                return notify_fail ("�����˭��·��\n");
        
        if (!ob1 = find_living(str))
                ob1 = LOGIN_D->find_body(str);
        if (ob1 == me) 
                return notify_fail("���Լ���·��\n");
        if(!objectp(ob2 = present(str, environment(me))) )
                return notify_fail("����û " + str + " ����ˡ�\n");
        if( !living(ob2) ) 
                return notify_fail("���" + ob1->name() + "������˵�ɡ�\n");            
        if (!userp(ob2) ) 
                return notify_fail("��ֻ�ܸ���Ҵ�·��\n");

        if( query_ip_number(me) == query_ip_number(ob2) )
        {
                command( "say ��λ����һ��ֱ��ָ·���ǣ��ֺα��������أ�\n" );
                command( "admit " + me->query("id") );
                command( "admit " + ob2->query("id" ) );
                return 1;
        }

        if( !ob2->query_temp("wg_road"))
                return notify_fail( "�Է���û�����˴�·��\n" );
        if( ob2->query_temp( "wg_road" ) == 1)
                return notify_fail( "��֪���Է�Ҫȥ��������\n" );
        
        if( me->query("combat_exp") < 100000 )
        {
                command("smile " + me->query("id"));
                return  notify_fail( RANK_D->query_respect(me)
                        + "���д��ģ����ǰ��˴����˿ɲ��Ǻ���ġ�\n" );
        }

        if( me->query_temp( "wg_lead" ) )
                return notify_fail( "�㲻���Ѿ��ڸ��˴�·����\n" );
        
        command( "thank " + me->query("id" ));
        
        if( ob2->query_temp( "wg_go" ) == "����" )
        {
                message_vision( sprintf(HIC "�������˵������Ȼ��ˣ�����" 
                        + RANK_D->query_respect( me ) + "����λ" + RANK_D->query_respect( ob2 ) + "��ȥ"
                        + HIY "�����巨����"HIC"����\n" NOR), me );
                me->set_temp("wg_goto", "qingfa biqiu" );
        }
        else if( ob2->query_temp( "wg_go" ) == "�䵱" )
        {
                message_vision( sprintf(HIC "�������˵������Ȼ��ˣ�����" 
                        + RANK_D->query_respect( me ) + "����λ" + RANK_D->query_respect( ob2 ) + "��ȥ"
                        + HIY "�䵱�������"HIC"����\n" NOR), me );
                me->set_temp("wg_goto", "guxu" );
        }
        else if( ob2->query_temp( "wg_go" ) == "��ü" )
        {
                message_vision( sprintf(HIC "�������˵������Ȼ��ˣ�����" 
                        + RANK_D->query_respect( me ) + "����λ" + RANK_D->query_respect( ob2 ) + "��ȥ"
                        + HIY "��ü����ʦ̫"HIC"����\n" NOR), me );
                me->set_temp("wg_goto", "jingxian" );
        }
        else if( ob2->query_temp( "wg_go" ) == "ؤ��" )
        {
                message_vision( sprintf(HIC "�������˵������Ȼ��ˣ�����" 
                        + RANK_D->query_respect( me ) + "����λ" + RANK_D->query_respect( ob2 ) + "��ȥ"
                        + HIY "ؤ���ɳ���"HIC"����\n" NOR), me );
                me->set_temp("wg_goto", "xi zhanglao" );
        }
        else if( ob2->query_temp( "wg_go" ) == "����" )
        {
                message_vision( sprintf(HIC "�������˵������Ȼ��ˣ�����" 
                        + RANK_D->query_respect( me ) + "����λ" + RANK_D->query_respect( ob2 ) + "��ȥ"
                        + HIY "����ߺ�ү"HIC"����\n" NOR), me );
                me->set_temp("wg_goto", "gao shengtai" );
        }
        else if( ob2->query_temp( "wg_go" ) == "Ľ��" )
        {
                message_vision( sprintf(HIC "�������˵������Ȼ��ˣ�����" 
                        + RANK_D->query_respect( me ) + "����λ" + RANK_D->query_respect( ob2 ) + "��ȥ"
                        + HIY "����Ľ�ݰ���ͬ"HIC"����\n" NOR), me );
                me->set_temp("wg_goto", "bao butong" );
        }
        else if( ob2->query_temp( "wg_go" ) == "����ׯ" )
        {
                message_vision( sprintf(HIC "�������˵������Ȼ��ˣ�����" 
                        + RANK_D->query_respect( me ) + "����λ" + RANK_D->query_respect( ob2 ) + "��ȥ"
                        + HIY "����ׯ½�˷�"HIC"����\n" NOR), me );
                me->set_temp("wg_goto", "lu chengfeng" );
        }
        else if( ob2->query_temp( "wg_go" ) == "������" )
        {
                message_vision( sprintf(HIC "�������˵������Ȼ��ˣ�����" 
                        + RANK_D->query_respect( me ) + "����λ" + RANK_D->query_respect( ob2 ) + "��ȥ"
                        + HIY "�������ŵ���"HIC"����\n" NOR), me );
                me->set_temp("wg_goto", "zhang danyue" );
        }
        else if( ob2->query_temp( "wg_go" ) == "����" )
        {
                message_vision( sprintf(HIC "�������˵������Ȼ��ˣ�����" 
                        + RANK_D->query_respect( me ) + "����λ" + RANK_D->query_respect( ob2 ) + "��ȥ"
                        + HIY "����������"HIC"����\n" NOR), me );
                me->set_temp("wg_goto", "yin wushou" );
        }
        else if( ob2->query_temp( "wg_go" ) == "����" )
        {
                message_vision( sprintf(HIC "�������˵������Ȼ��ˣ�����" 
                        + RANK_D->query_respect( me ) + "����λ" + RANK_D->query_respect( ob2 ) + "��ȥ"
                        + HIY "���ް���"HIC"����\n" NOR), me );
                me->set_temp("wg_goto", "a zi" );
        }
        else if( ob2->query_temp( "wg_go" ) == "��ɽ" )
        {
                message_vision( sprintf(HIC "�������˵������Ȼ��ˣ�����" 
                        + RANK_D->query_respect( me ) + "����λ" + RANK_D->query_respect( ob2 ) + "��ȥ"
                        + HIY "��ɽ����Ⱥ����"HIC"����\n" NOR), me );
                me->set_temp("wg_goto", "yue buqun" );
        }
        else if( ob2->query_temp( "wg_go" ) == "������" )
        {
                message_vision( sprintf(HIC "�������˵������Ȼ��ˣ�����" 
                        + RANK_D->query_respect( me ) + "����λ" + RANK_D->query_respect( ob2 ) + "��ȥ"
                        + HIY "������ɣ������"HIC"����\n" NOR), me );
                me->set_temp("wg_goto", "sangjie" );
        }

        command( "say �����ҹ��������Ϊƾ֤��" );
        message_vision( sprintf(HIW "�����������$Nһ��"HIR"�������"HIW"��\n" NOR), me);
        new("/d/wuguan/obj/lingpai")->move( me );
        me->set_temp("wg_lead",1);
        ob2->delete_temp("wg_road");
        message_vision( HIW "$N��������$nһ���ж���\n" NOR, ob2, me );
        ob2->set_leader(me);
        call_out( "remove_lead", 600, me, ob2 );
        return 1;
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) 
                return;
        if ( ob->query("combat_exp") < 10000)  
        switch( random( 3 ) )
        {
                case 2:
                        command("say ��λ" + RANK_D->query_respect(ob)+"���书��ô���ô�������أ�\n");
                        break;
        case 1:
                        command( "say " + RANK_D->query_respect( ob )
                                + "�����Ҫ�̲�����ѧ�ѣ�����ͨ�������Ұ�æ("HIY"ask wei about ����"CYN")��" );
                        break;
        case 0:
                        command( "say " + RANK_D->query_respect( ob )
                                + "�������ʶ·���ҿ��Դ���������·("HIY"ask wei about ��·"CYN")��" );
                        break;
        }
}

string ask_xin()
{
	object me = this_player();
	object letter;
	//interactive ���� 0
	
	if (me->query("enter_wuguan"))
		return "�ţ�ʲô�ţ�û��˵����";
	if( me->query("combat_exp") > 5000000 )
        {
                return RANK_D->query_respect(me) + 
                        "���书�Ѿ����ͣ���������Ͳ��������ˣ�";
        }
        if(mapp(me->query("forging")))
        {
        	return RANK_D->query_respect(me) + 
                        "����֪���ˣ��������ң���Ҳ���ǣ���";
        }
        if ( me->query("dazao/give") )
        {
        	return "�������㲻���Ѿ��͹�ȥ��ô��";
        }
        if( present("shu xin", me))
        {
        	return "�����ϲ�������ô��";
        }
        if(objectp(letter = new(__DIR__"obj/letter")))
        {
        command("whisper "+getuid(me)+" �ٺ٣���ô��С�Ķ��˹���������ţ�С�Ĺ�������PP!");
        letter->move(me);
        command("say �����ﻹ��һ�⣬�������ȥ�ɣ����չ�����˰ɣ�");
        letter->move(me);
        message_vision("$n��$Nһ�⡸"+letter->query("name")+"����\n",me,  this_object());   
        return "����㲻��ұ������֮��������ʹ�� help dazao �����ϸ��Ϣ��"; 
        }
        return 0;                
}

void test_job(object ob)
{
        if( !ob || environment(ob) != environment() ) 
                return;

        ob->add_temp("job_party", 1);
        call_out("test_job", 10, ob);
}

void do_job(object me, object tar)
{
        object *list;
        object target, obj;
        string *file, where, dir;

        object ob = this_object();

        if( !me ) return;
        if( !me->query("family/family_name") ) return;
        if( wizardp(me) ) return;


        if( ob->query_temp("count") > 10 ) {
                ob->delete_temp("count");
                return;
        }

        list = filter_array(users(), (: $1->query("combat_exp") >= 100000 && !wizardp($1) :));

        if( sizeof(list) > 0 ) target = list[(random(sizeof(list)))];

        if( !target ) {
                if( wizardp(tar) ) tell_object(tar, YEL"����ûָ�����󣬷���...\n"NOR);
                ob->add_temp("count",1);
                call_out("do_job", 1, me, tar);
                return;
        } else if( wizardp(tar) ) tell_object(tar, RED"������"+target->name()+"("+target->query("id")+")\n"NOR);

        if( target->query("id") == me->query("id") || wizardp(target)
         || target->query("family/family_name") == me->query("family/family_name") ) {
                if( wizardp(tar) ) tell_object(tar, HIY"����Ҫ�����¼��...\n"NOR);
                ob->add_temp("count",1);
                call_out("do_job", 1, me, tar);
                return;

        } else {
                switch(me->query("family/family_name")){
                	case "������": dir = "/d/emei/"; break;
                	case "������": dir = "/d/shaolin/"; break;
                	case "������": dir = "/d/tls/"; break;
                	case "�䵱��": dir = "/d/wudang/"; break;
                	case "��ɽ��": dir = "/d/huashan/"; break;
                	case "��ɽ��": dir = "/d/songshan/"; break;
                	case "����Ľ��": dir = "/d/mr/yanziwu/"; break;
                	case "����": dir = "/d/mingjiao/"; break;
                	case "������": dir = "/d/sld/"; break;
                	case "��Ĺ��": dir = "/d/gumu/"; break;
                	case "ؤ��": dir = "/d/gb/"; break;
                	case "���ư�": dir = "/d/tiezhang/"; break;
                	case "����": dir = "/d/dali/"; break;
                	case "������": dir = "/d/xueshan/"; break;
                	case "�һ���": dir = "/d/thd/"; break;
                	case "������": dir = "/d/kunlun/"; break;
                	case "������": dir = "/d/xingxiu/"; break;
                	default: return; break;
                }

                file = get_dir(dir);
                if( sizeof(file) > 0 ) file = filter_array(file, (: sort_file :) );
                where = dir + file[random(sizeof(file))];

                if( wizardp(tar) ) tell_object(tar, YEL"�ص㣺"+where+YEL"��"+where->query("short")+YEL"��\n"NOR);
                if( wizardp(tar) ) tell_object(tar, YEL"����"+target->name()+"("+target->query("id")+")\n"NOR);
                obj = new(__DIR__"job_npc");
                obj->do_copy(target);
                obj->move(where);
                obj->set("family/family_name", target->query("family/family_name"));
                obj->set("kill_party", me->query("family/family_name"));

                CHANNEL_D->do_channel(me, "party", "��˵�и�"+obj->query("title")+"��ð" + target->query("family/family_name") + 
                HIR + target->query("name") + HIW + "(" + target->query("id") + ")" + HIG
                "֮������" + me->query("family/family_name") + HIR + where->query("short") + HIG + 
                "һ���������ơ�\n");
                CHANNEL_D->do_channel(me, "party", HIY"�ö����Ը��书�˵ã������ˣ���"HIC + me->query("family/family_name") + HIY"���������������в����Ĵ�����\n"NOR);
        }
}

