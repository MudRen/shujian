// Room: /d/xiangyang/damen.c ����
// Modify By River 98/10
// Modify By Lklv 2001.9.21
// Modify by tangfeng for ���Ǿ�quest

inherit ROOM;
#include <ansi.h>
#include <room.h>
#include <wanted.h>
#include "/d/suzhou/npc/lchj.h";//���Ǿ�

void create()
{
	set("short", HIY"��ݴ���"NOR);
	set("long", "������������ݵĴ��ţ����Ⱥ������ľ�������ҳ����ţ��ſڵ����Ϸ�\n"+
"������һ��ڵ׽��ֵĴ��ң�����д���ĸ����֣���"+HIY"������o"NOR+"��������������\n"+
"��������һ��������\n\n"+
HIC"          ���׶��x�σ��в����y���M��\n\n"NOR+
HIC"          ��ǧ�Ŷ�Թ�������hһ�ؿա�\n\n"NOR+
"��ǰ��̨�����Ը�����һ��ʯʨ���Ӵ��ſ���������ȥ����ݵ�Ժ����������\n"+
"����ææµµ�����ſڸ��ǳ�ˮ��������������������Ϣ�������Ա�վ��һ��\n"+
"������������������ȴ�ֱ������²�ɣ��\n"
        );
	set("outdoors","���");
        set("xyjob", 1);
	set("no_fight", 1);
	set("exits", ([
		"south" : __DIR__"eroad1",
		"enter": "/d/wuguan/menlang",
	]));
	set("objects", ([
                "/d/wuguan/npc/menwei" : 1,
//                "/tmp/ciwei/menwei" : 1,
	]));
	set("incity",1);
	setup();
}

int valid_leave(object me,string dir)
{
        object *obj;
	int x;

	if ( me->query_temp( "wg_help" ) || me->query_temp( "wg_road" ) == 2 )
		return notify_fail("�������˵����" + RANK_D->query_respect(me) +
			"���������ĵ�һ��ɣ�˵�������Ͼ����������������\n");
	if ( me->query_temp( "wg_juanzeng" ) )
		me->delete_temp( "wg_juanzeng" );
	if ( me->query_temp( "wg_road" ) == 1 )
		me->delete_temp( "wg_road" );
	if ( dir == "enter" ) {
		if ( is_wanted(me) )
			return 0;
		if ( me->query("combat_exp") > 3000 )
		{
			if(!me->query(QUESTDIR1+"over") || me->query(QUESTDIR2+"over")) //������ɾ���һ��û�н������ߵڶ������Ѿ���ɣ����޷��������
				return notify_fail("������ǰ����һ�죺����书�����ˣ������ѧ����ʲô�ˡ�\n");
			if(me->query_temp(QUESTDIR2+"start")) //������ʧ����
			{
				message_vision(HIY"\n�����ɻ�ؿ���$N����$N�ղ���ô��ȥ�ֳ����ˣ�\n", me);
				me->delete_temp("quest/busy");//
				me->delete_temp(QUESTDIR);
				if(random(2)) return notify_fail("������ǰ����һ�죺������ô�õ����飬����ݽ���������\n");
				else return notify_fail("������ǰ����һ�죺����ν��̽���ѵ���ƭ�ҵģ�\n");		
			}
			obj = users();
			x = sizeof(obj);
			while(x--)
			{
				if ( obj[x]->query_temp(QUESTDIR2+"start") && obj[x]!=me ) 
					return notify_fail("������ǰ����һ�죺"+obj[x]->query("name")+RANK_D->query_respect(obj[x]) +"�Ѿ�ȥ���̽��ȥ�ˣ����ٵȵȣ�\n");		  
			}
	   message_vision(HIY"\n$N��ͷ�ƺ�������˵��Щʲô����������һ�����˳�����\n"NOR, me);
     if(me->query(QUESTDIR+"time")&&time()-me->query(QUESTDIR+"time")<86400)
			    return notify_fail("������ǰ����һ�죺���������������æ�ˣ�"+RANK_D->query_respect(me) +"������Ϣȥ�ɣ�\n");		  
	   if(me->query(QUESTDIR+"combat_exp")&&me->query("combat_exp")-me->query(QUESTDIR+"combat_exp")<50000)
			   return notify_fail("������ǰ����һ�죺��"+RANK_D->query_respect(me) +"Ŀǰ�ľ�������ȥ��Ҳ������ʲô������ץ�������ɣ�\n");

	   	message_vision(HIY"ֻ���������Ա�һ����$N���ŷ��Ｗ�˽�ȥ��\n"NOR, me);
		  me->set(QUESTDIR+"time",time());
		  me->set(QUESTDIR+"combat_exp",me->query("combat_exp")); 
		  me->set(QUESTDIR2+"start",1);//��ʼ
		  me->set_temp(QUESTDIR2+"start",1);
		  me->set_temp("quest/busy",1);
	}
	}
	return ::valid_leave(me, dir);
}
