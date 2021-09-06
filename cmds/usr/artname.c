// artname.c
// by snowman@SJ 22/05/2000
// bbb ˵�ӵ�ϻ����Ա���£�����

inherit F_CLEAN_UP;
inherit F_SAVE;
#define LIMIT 11

#include <ansi.h>
#include <database.h>


nosave string *banned_sword_name = ({
"ɱ��", "����","��ң","ѩ��", "ĳ��","�����","ȥ���", "ë��", "��Сƽ", "������", "��ʦ",
"�齣", "������", "������","��ӹ", "����","����", "����", "���", "���","������",
});

mapping artnames;
mapping query_artnames(){ return artnames; }

int remove()
{
        save();
        return 1;
}

string query_save_file()
{
        return "/log/artname_vote";
}

void create()
{
	seteuid(getuid());
        restore();
        if(!artnames) artnames = ([ ]);
}

string clean_all()
{
        artnames = ([ ]);
        remove();
        return "����ȫ�������ϡ�\n";
}

string clean_name(string name)
{
	map_delete(artnames, name);
        remove();
        return name+"�����������ϡ�\n";
}

int check_legal_name(string name)
{
	int i = strlen(name);
	if (i < 4 || i > 10 || i%2) {
		write("�Բ�����Ҫ����ĵ���ű����Ƕ�����������֡�\n");
		return 0;
	}

	while(i--)
		if( i%2==0 && !is_chinese(name[i..<0]) ) {
			write("�Բ��������á����ġ�ȡ��š�\n");
			return 0;
		}

	if( member_array(name, banned_sword_name)!=-1 ) {
		write("�Բ���������Ż���������˵����š�\n");
		return 0;
	}
	return 1;
}

int main(object me, string str)
{
	object ob;
	mapping mp;
	string art, artname;
	int i;
	
	if ( me->is_busy() || me->is_fighting() )
		return notify_fail("����æ���أ�����������˵�ɡ�\n");	
	
	if ( base_name(environment(me)) != "/d/city/jiulou2") 
		return notify_fail("����뵽�����˾ۼ��ĵط�����������˵���ţ����磺������������¥��\n");

	if ( !str ) 
		return notify_fail("�����ҪΪ˭��������������û�У���ʽ�� artname <id> <���> \n");	
	
	if (sscanf(str, "%s %s", str, art) != 2 )
	 	return notify_fail("�����ҪΪ˭��������������û�У���ʽ�� artname <id> <���> \n");
	
	if ( str == "-clear" && wizardp(me) ){
		if( art == "all" )
			return notify_fail(clean_all());
		else 	return notify_fail(clean_name(art));
	}
	
		
	if ( str == me->query("id") && !wizardp(me) )
		return notify_fail("���Լ��𣿽����ɲ��ǰ�Ҽң��ñ�����ͬ���У�\n");	
	
	if ( me->query("combat_exp") < 100000 )
		return notify_fail("���ڽ������������������������û�ʸ����������Űɣ�\n");	
				
	if( !check_legal_name(art) ) 
		return notify_fail(HIW"������鲻�ã����������\n"NOR);
	
	ob = LOGIN_D->find_body(str);
	if ( !ob ) ob = find_living(str);
	
	if( !mapp(mp = artnames[str] ) ){
		if(sizeof(keys(artnames)) >= LIMIT ) 
			return notify_fail("�Բ���Ŀǰֻ������ͬʱ����ʮ���˵�����š�\n"NOR);
		if ( !ob || !me->visible(ob)) 
			return notify_fail(YEL"\n��Ҫ�������Ŀǰ������Ϸ�У��ȴ��˽�����Ϸ��˵�ɡ�\n\n"NOR);
		if ( stringp(artname = ob->query("artname")) 
		&& artname != "" 
		&& ob->query("artname_time")
		&& time()*60 > ob->query("artname_time") ) // ʮ����ܻ�һ�Ρ�
			return notify_fail("�����Ѿ����������������"+artname+"����Ҫ��������ţ��õ�ʮ��һ�εĻ��ᡣ\n");	
		
		if ( art == ob->query("name") )
			return notify_fail("�����źʹ��˵�������ͬҮ�������ģ�\n");	

		artnames[str] = ([ art : ({ me->query("id"),query_ip_number(me)  })  ]);
		//artnames[str] = ([ art : ([ me->query("id"): ])  ]);
	}
	
	else {
		if ( sizeof(keys(artnames[str])) >= 9 )
			return notify_fail(YEL"\n�Բ�����������Ÿ���ţ��������еľŸ���ѡ��\n\n"NOR);
		if( artnames[str][art] && member_array(me->query("id"), artnames[str][art] )!=-1 ) 
			return notify_fail(YEL"\n�Բ��������Ը�һ�����Ͷһ��Ʊ��\n\n"NOR);
		if( artnames[str][art] && member_array(query_ip_number(me), artnames[str][art] )!=-1 ) 
			return notify_fail(YEL"\n�Բ���ͬһ���ߵ�ַ�����Ը�һ�����Ͷһ��Ʊ��\n\n"NOR);
		if( !artnames[str][art] )
			artnames[str] += ([ art : ({ me->query("id"),query_ip_number(me) }) ]);
		else 	artnames[str][art] += ({ me->query("id"),query_ip_number(me) });
	}
	
	i = sizeof(artnames[str][art]);
	message_vision(MAG"\n$N����ǰȥ������ھ���һ�ӣ�������ͬ�ѡ�"+art+"�������Ÿ� "+capitalize(str)+"����\n"NOR, me);
	i /=2;	
	write("\n���ھ��϶����һ����������Ŀǰ���� "+to_chinese(i)+" ���޳ɡ�\n");
        if( (i > 30 && ob) || wizardp(me))
	//if( i > 1 && ob )
	{
		call_out("give_artname", 1, ob, art );
		map_delete(artnames, str);
	}
	
	return 1;
}

void give_artname(object ob, string art)
{
	if ( !ob || !stringp(art) ) return;
	//ob->set("artname", art);
	//ob->set("artname_time", time()*60 + 31536000 );  // ʮ�ꡣ
	//ob->save();
	BBS_D->add_Bbs_Up_Map(WEB_DB_NAME, "UPDATE members SET title = '"+strip(art)+"' WHERE username = '"+ob->query("id")+"@"+lower_case(INTERMUD_MUD_NAME)+"'");
	//message("wizard:linux", "UPDATE members SET title = '"+strip(art)+"' WHERE username = '"+ob->query("id")+"@"+lower_case(INTERMUD_MUD_NAME)+"'", users());
	message("chat", HIY +"\n���������ԡ���������ͬ������ͨ����"+ob->name(1)+"���齣��̳("+HIW+U+"http://bbs.mymud.com"+NOR+HIY+")����µ���ţ�"+HIG+art+HIY+"��\n"NOR, users());
}
