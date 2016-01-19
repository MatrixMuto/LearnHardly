[ReactiveX](http://reactivex.io/)

[Introduction to Rx](http://www.introtorx.com/)

```Java
    static Observable<String> sampleObservable() {
        return Observable.defer(new Func0<Observable<String>>() {
            @Override public Observable<String> call() {
                try {
                    // Do some long running operation
                    Thread.sleep(TimeUnit.SECONDS.toMillis(5));
                } catch (InterruptedException e) {
                    throw OnErrorThrowable.from(e);
                }
                return Observable.just("one", "two", "three", "four", "five");
            }
        });
    }
```

```Java
public interface Func0<R> extends Function, Callable<R> {
    @Override
    R call();
}
```

```Java
public class Observable<T> {
...
}
```
```Java
public final static <T> Observable<T> just(T t1, T t2, T t3, T t4, T t5) {
    return from(Arrays.asList(t1, t2, t3, t4, t5));
}
```    
```Java
public final static <T> Observable<T> defer(Func0<Observable<T>> observableFactory) {
    return create(new OnSubscribeDefer<T>(observableFactory));
}
```

